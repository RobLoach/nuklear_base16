#define NK_TINTED_IMPLEMENTATION
#include "../../nuklear_tinted.h"

/* Every scheme, as tinted_schemes */
#define TINTED_IMPLEMENTATION
#include "../../vendor/tinted-c/include/tinted.h"

#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
/* The overview must match the nuklear.h in use, so backends bundling their own may override it */
#ifndef NK_TINTED_DEMO_OVERVIEW
#define NK_TINTED_DEMO_OVERVIEW "../../vendor/nuklear/demo/common/overview.c"
#endif
#include NK_TINTED_DEMO_OVERVIEW

static int selected_scheme = -1;

void nuklear_tinted_demo(struct nk_context* ctx, int screenWidth, int screenHeight) {
    int flags = NK_WINDOW_TITLE | NK_WINDOW_BORDER;
    int width = 300;

    if (selected_scheme == -1) {
        selected_scheme = 0;
        nuklear_tinted_set_scheme(ctx, tinted_schemes[selected_scheme]);
    }

    if (nk_begin(ctx, "Tinted", nk_rect(screenWidth - width, 0, width, screenHeight), flags)) {
        nk_layout_row_dynamic(ctx, 0, 1);

        for (int i = 0; i < TINTED_COUNT; i++) {
            nk_bool active = selected_scheme == i;
            if (nk_radio_label(ctx, tinted_schemes[i]->name, &active)) {
                nuklear_tinted_set_scheme(ctx, tinted_schemes[i]);
                selected_scheme = i;
            }

        }
    }
    nk_end(ctx);

    overview(ctx);
}
