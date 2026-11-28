/**
 * nuklear_tinted: Base16, Base24 and Tinted8 Color Themes for Nuklear
 * https://github.com/robloach/nuklear_tinted
 *
 * @file nuklear_tinted.h
 *
 * License: MIT
 *
 * Copyright (c) 2024 Rob Loach (https://robloach.net)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef NUKLEAR_TINTED_H
#define NUKLEAR_TINTED_H

/* Only the scheme types; the caller includes the schemes it uses. */
#include "vendor/tinted-c/include/tinted_types.h"

#ifdef __cplusplus
extern "C" {
#endif

NK_API void nuklear_tinted_set_scheme(struct nk_context* ctx, const tinted_scheme* scheme);
NK_API struct nk_color nuklear_tinted_color(const tinted_scheme* scheme, int index);
NK_API void nuklear_tinted_set_tinted8_scheme(struct nk_context* ctx, const tinted8_scheme* scheme);

#ifdef __cplusplus
}
#endif

#endif

#if defined(NK_TINTED_IMPLEMENTATION)
#ifndef NK_TINTED_IMPLEMENTATION_ONCE
#define NK_TINTED_IMPLEMENTATION_ONCE

#ifdef __cplusplus
extern "C" {
#endif

NK_API struct nk_color nuklear_tinted_color(const tinted_scheme* scheme, int index) {
    if (scheme == NULL || index < 0 || index >= 24) {
        return nk_rgba(0, 0, 0, 255);
    }
    return nk_rgba(scheme->base[index].r, scheme->base[index].g, scheme->base[index].b, 255);
}

NK_API void nuklear_tinted_set_scheme(struct nk_context* ctx, const tinted_scheme* scheme) {
    struct nk_color table[NK_COLOR_COUNT];
    if (scheme == NULL) {
        return;
    }

    // base00 - Default Background
    // base01 - Lighter Background (Used for status bars, line number and folding marks)
    // base02 - Selection Background
    // base03 - Comments, Invisibles, Line Highlighting
    // base04 - Dark Foreground (Used for status bars)
    // base05 - Default Foreground, Caret, Delimiters, Operators
    // base06 - Light Foreground (Not often used)
    // base07 - Brightest Foreground (Not often used)
    // base08 - Variables, XML Tags, Markup Link Text, Markup Lists, Diff Deleted
    // base09 - Integers, Boolean, Constants, XML Attributes, Markup Link Url
    // base0A - Classes, Markup Bold, Search Text Background
    // base0B - Strings, Inherited Class, Markup Code, Diff Inserted
    // base0C - Support, Regular Expressions, Escape Characters, Markup Quotes
    // base0D - Functions, Methods, Attribute IDs, Headings
    // base0E - Keywords, Storage, Selector, Markup Italic, Diff Changed
    // base0F - Deprecated, Opening/Closing Embedded Language Tags, e.g. <?php ?>

    table[NK_COLOR_TEXT] = nuklear_tinted_color(scheme, 5);
    table[NK_COLOR_WINDOW] = nuklear_tinted_color(scheme, 0);
    table[NK_COLOR_HEADER] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_BORDER] = nuklear_tinted_color(scheme, 2);

    table[NK_COLOR_BUTTON] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_BUTTON_HOVER] = nuklear_tinted_color(scheme, 2);
    table[NK_COLOR_BUTTON_ACTIVE] = nuklear_tinted_color(scheme, 3);

    table[NK_COLOR_TOGGLE] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_TOGGLE_HOVER] = nuklear_tinted_color(scheme, 2);
    table[NK_COLOR_TOGGLE_CURSOR] = nuklear_tinted_color(scheme, 0x0D);

    table[NK_COLOR_SELECT] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_SELECT_ACTIVE] = nuklear_tinted_color(scheme, 2);

    table[NK_COLOR_SLIDER] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_SLIDER_CURSOR] = nuklear_tinted_color(scheme, 5);
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = nuklear_tinted_color(scheme, 0x0D);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nuklear_tinted_color(scheme, 0x0D);

    table[NK_COLOR_PROPERTY] = nuklear_tinted_color(scheme, 1);

    table[NK_COLOR_EDIT] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_EDIT_CURSOR] = nuklear_tinted_color(scheme, 5);

    table[NK_COLOR_COMBO] = nuklear_tinted_color(scheme, 1);

    table[NK_COLOR_CHART] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_CHART_COLOR] = nuklear_tinted_color(scheme, 0x0D);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nuklear_tinted_color(scheme, 9);

    table[NK_COLOR_SCROLLBAR] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_SCROLLBAR_CURSOR] = nuklear_tinted_color(scheme, 4);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nuklear_tinted_color(scheme, 5);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nuklear_tinted_color(scheme, 0x0D);

    table[NK_COLOR_TAB_HEADER] = nuklear_tinted_color(scheme, 1);

    table[NK_COLOR_KNOB] = table[NK_COLOR_SLIDER];
    table[NK_COLOR_KNOB_CURSOR] = table[NK_COLOR_SLIDER_CURSOR];
    table[NK_COLOR_KNOB_CURSOR_HOVER] = table[NK_COLOR_SLIDER_CURSOR_HOVER];
    table[NK_COLOR_KNOB_CURSOR_ACTIVE] = table[NK_COLOR_SLIDER_CURSOR_ACTIVE];

    nk_style_from_table(ctx, table);
}

NK_INTERN struct nk_color nuklear_tinted8_rgb(tinted_color color) {
    return nk_rgba(color.r, color.g, color.b, 255);
}

NK_API void nuklear_tinted_set_tinted8_scheme(struct nk_context* ctx, const tinted8_scheme* scheme) {
    struct nk_color table[NK_COLOR_COUNT];
    struct nk_color text, window, chrome, border, widget, recessed, selected, muted, caret, accent, info;
    int light;
    if (scheme == NULL) {
        return;
    }

    // The Tinted8 builder's default ui roles, which swap black and white for light schemes.
    // https://github.com/tinted-theming/home/blob/main/specs/tinted8/builder.md
    light = scheme->variant != NULL && scheme->variant[0] == 'l';
    text = nuklear_tinted8_rgb(light ? scheme->black.normal : scheme->white.normal); // ui.global.normal.foreground
    window = nuklear_tinted8_rgb(light ? scheme->white.normal : scheme->black.normal); // ui.global.normal.background
    chrome = nuklear_tinted8_rgb(light ? scheme->white.dim : scheme->black.bright); // ui.chrome.normal.background
    border = nuklear_tinted8_rgb(light ? scheme->gray.bright : scheme->gray.dim); // ui.border.normal
    widget = nuklear_tinted8_rgb(light ? scheme->white.dim : scheme->black.bright); // ui.highlight.button.background
    recessed = nuklear_tinted8_rgb(light ? scheme->white.bright : scheme->black.dim); // ui.global.dark.background
    selected = nuklear_tinted8_rgb(scheme->gray.normal); // ui.highlight.text.active.background
    muted = nuklear_tinted8_rgb(light ? scheme->black.bright : scheme->white.dim); // ui.global.dark.foreground
    caret = nuklear_tinted8_rgb(light ? scheme->black.normal : scheme->white.normal); // ui.cursor.normal.background
    accent = nuklear_tinted8_rgb(scheme->cyan.normal); // ui.accent.normal
    info = nuklear_tinted8_rgb(scheme->orange.normal); // ui.status.info

    table[NK_COLOR_TEXT] = text;
    table[NK_COLOR_WINDOW] = window;
    table[NK_COLOR_HEADER] = chrome;
    table[NK_COLOR_BORDER] = border;

    // Hover sinks into the recessed surface, which keeps the text readable on it.
    table[NK_COLOR_BUTTON] = widget;
    table[NK_COLOR_BUTTON_HOVER] = recessed;
    table[NK_COLOR_BUTTON_ACTIVE] = selected;

    table[NK_COLOR_TOGGLE] = widget;
    table[NK_COLOR_TOGGLE_HOVER] = recessed;
    table[NK_COLOR_TOGGLE_CURSOR] = accent;

    table[NK_COLOR_SELECT] = widget;
    table[NK_COLOR_SELECT_ACTIVE] = selected;

    table[NK_COLOR_SLIDER] = widget;
    table[NK_COLOR_SLIDER_CURSOR] = text;
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = accent;
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = accent;

    table[NK_COLOR_PROPERTY] = widget;

    table[NK_COLOR_EDIT] = widget;
    table[NK_COLOR_EDIT_CURSOR] = caret;

    table[NK_COLOR_COMBO] = widget;

    table[NK_COLOR_CHART] = widget;
    table[NK_COLOR_CHART_COLOR] = accent;
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = info;

    table[NK_COLOR_SCROLLBAR] = widget;
    table[NK_COLOR_SCROLLBAR_CURSOR] = muted;
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = text;
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = accent;

    table[NK_COLOR_TAB_HEADER] = widget;

    table[NK_COLOR_KNOB] = table[NK_COLOR_SLIDER];
    table[NK_COLOR_KNOB_CURSOR] = table[NK_COLOR_SLIDER_CURSOR];
    table[NK_COLOR_KNOB_CURSOR_HOVER] = table[NK_COLOR_SLIDER_CURSOR_HOVER];
    table[NK_COLOR_KNOB_CURSOR_ACTIVE] = table[NK_COLOR_SLIDER_CURSOR_ACTIVE];

    nk_style_from_table(ctx, table);
}

#ifdef __cplusplus
}
#endif

#endif  // NK_TINTED_IMPLEMENTATION_ONCE
#endif  // NK_TINTED_IMPLEMENTATION
