#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

#include <SDL3/SDL.h>

/* Use SDL3's main callbacks for a portable entry point and event loop.
 * See: https://wiki.libsdl.org/SDL3/README-main-functions */
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_COMMAND_USERDATA
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT

/* Reuse SDL's portable types and libc replacements */
#define NK_INT8              Sint8
#define NK_UINT8             Uint8
#define NK_INT16             Sint16
#define NK_UINT16            Uint16
#define NK_INT32             Sint32
#define NK_UINT32            Uint32
#define NK_SIZE_TYPE         uintptr_t
#define NK_POINTER_TYPE      uintptr_t
#define NK_BOOL              bool
#define NK_ASSERT(condition) SDL_assert(condition)
#define NK_MEMSET(dst, c, len)    SDL_memset(dst, c, len)
#define NK_MEMCPY(dst, src, len)  SDL_memcpy(dst, src, len)
#define NK_VSNPRINTF(s, n, f, a)  SDL_vsnprintf(s, n, f, a)

#define NK_IMPLEMENTATION
#include "../../vendor/nuklear/nuklear.h"
#define NK_SDL3_RENDERER_IMPLEMENTATION
#include "../../vendor/nuklear/demo/sdl3_renderer/nuklear_sdl3_renderer.h"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 720

#include "../common/nuklear_base16_demo.c"

struct app_state {
    SDL_Window *window;
    SDL_Renderer *renderer;
    struct nk_context *ctx;
};

static SDL_AppResult app_fail(void) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error: %s", SDL_GetError());
    return SDL_APP_FAILURE;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    struct app_state *app;
    float font_scale;
    NK_UNUSED(argc);
    NK_UNUSED(argv);

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        return app_fail();
    }

    app = SDL_calloc(1, sizeof(*app));
    if (app == NULL) {
        return app_fail();
    }
    *appstate = app;

    if (!SDL_CreateWindowAndRenderer("nuklear_base16_demo", WINDOW_WIDTH, WINDOW_HEIGHT,
            SDL_WINDOW_RESIZABLE, &app->window, &app->renderer)) {
        return app_fail();
    }
    SDL_SetRenderVSync(app->renderer, 1);

    /* Scale rendering for high DPI displays */
    font_scale = SDL_GetWindowDisplayScale(app->window);
    if (font_scale <= 0.0f) {
        font_scale = 1.0f;
    }
    SDL_SetRenderScale(app->renderer, font_scale, font_scale);

    app->ctx = nk_sdl_init(app->window, app->renderer, nk_sdl_allocator());
    {
        struct nk_font_atlas *atlas;
        struct nk_font_config config = nk_font_config(0);
        struct nk_font *font;

        atlas = nk_sdl_font_stash_begin(app->ctx);
        font = nk_font_atlas_add_default(atlas, 13 * font_scale, &config);
        nk_sdl_font_stash_end(app->ctx);

        /* Bake at the display scale, then draw at logical size */
        font->handle.height /= font_scale;
        nk_style_set_font(app->ctx, &font->handle);
    }

    nk_input_begin(app->ctx);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    struct app_state *app = (struct app_state *)appstate;

    switch (event->type) {
        case SDL_EVENT_QUIT:
            return SDL_APP_SUCCESS;
        case SDL_EVENT_KEY_UP:
            if (event->key.key == SDLK_ESCAPE) {
                return SDL_APP_SUCCESS;
            }
            break;
    }

    /* Map event coordinates into the scaled render space */
    SDL_ConvertEventToRenderCoordinates(app->renderer, event);
    nk_sdl_handle_event(app->ctx, event);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    struct app_state *app = (struct app_state *)appstate;
    int output_width, output_height;
    float scale_x, scale_y;

    nk_input_end(app->ctx);

    /* Render the base16 demo in logical (scaled) coordinates */
    SDL_GetCurrentRenderOutputSize(app->renderer, &output_width, &output_height);
    SDL_GetRenderScale(app->renderer, &scale_x, &scale_y);
    nuklear_base16_demo(app->ctx, (int)(output_width / scale_x), (int)(output_height / scale_y));

    SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
    SDL_RenderClear(app->renderer);

    nk_sdl_render(app->ctx, NK_ANTI_ALIASING_ON);
    nk_sdl_update_TextInput(app->ctx);

    SDL_RenderPresent(app->renderer);

    nk_input_begin(app->ctx);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    struct app_state *app = (struct app_state *)appstate;
    NK_UNUSED(result);

    if (app == NULL) {
        return;
    }
    if (app->ctx) {
        nk_input_end(app->ctx);
        nk_sdl_shutdown(app->ctx);
    }
    if (app->renderer) {
        SDL_DestroyRenderer(app->renderer);
    }
    if (app->window) {
        SDL_DestroyWindow(app->window);
    }
    SDL_free(app);
}
