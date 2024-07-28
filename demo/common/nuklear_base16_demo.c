#define NK_BASE16_IMPLEMENTATION
#include "../../nuklear_base16.h"

#include "../../vendor/nuklear/demo/common/overview.c"

int selected_scheme = -1;

void nuklear_base16_demo(struct nk_context* ctx) {
    int flags = NK_WINDOW_TITLE | NK_WINDOW_BORDER | NK_WINDOW_MOVABLE;
    int padding = 10;
    int width = 300;
    int height = WINDOW_HEIGHT - 2 * padding;

    if (selected_scheme == -1) {
        selected_scheme = 0;
        nuklear_base16_set_scheme(ctx, nuklear_base16_schemes[selected_scheme]);
    }

    if (nk_begin(ctx, "Base16", nk_rect(WINDOW_WIDTH - width - padding, padding, width, height), flags)) {
        nk_layout_row_dynamic(ctx, 0, 1);

        for (int i = 0; i < NK_BASE16_COUNT; i++) {
            nk_bool active = selected_scheme == i;
            if (nk_radio_label(ctx, nuklear_base16_schemes[i]->name, &active)) {
                nuklear_base16_set_scheme(ctx, nuklear_base16_schemes[i]);
                selected_scheme = i;
            }

        }

        nk_end(ctx);
    }

    overview(ctx);
}