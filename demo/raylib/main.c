#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#endif

#include "raylib.h"

#define RAYLIB_NUKLEAR_IMPLEMENTATION
#define RAYLIB_NUKLEAR_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#include "raylib-nuklear.h"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 720

#include "../common/nuklear_base16_demo.c"

void UpdateDrawFrame(void);

struct nk_context *ctx;
nk_bool shouldClose = nk_false;

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "nuklear_base16_demo");
    SetWindowMinSize(200, 200);

    // Create the Nuklear Context
    int fontSize = 13;
    Font font = LoadFontFromNuklear(fontSize);
    GenTextureMipmaps(&font.texture);
    ctx = InitNuklearEx(font, fontSize);

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
    #else
        while (!WindowShouldClose()) {
            UpdateDrawFrame();

            if (shouldClose) {
                break;
            }
        }
    #endif

    // De-initialize the Nuklear GUI
    UnloadNuklear(ctx);
    UnloadFont(font);

    CloseWindow();
    return 0;
}

void UpdateDrawFrame(void) {
    // Update the Nuklear context, along with input
    UpdateNuklear(ctx);

    nuklear_base16_demo(ctx, GetScreenWidth(), GetScreenHeight());

    // Render
    BeginDrawing();
        ClearBackground(BLACK);

        // Render the Nuklear GUI
        DrawNuklear(ctx);

    EndDrawing();

    #ifdef PLATFORM_WEB
        if (shouldClose) {
            emscripten_cancel_main_loop();
        }
    #endif
}
