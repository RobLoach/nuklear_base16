/**
 * nuklear_tinted: Base16 and Base24 Color Themes for Nuklear
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

/* Compile the tinted-c scheme data along with the nuklear_tinted implementation. */
#if defined(NK_TINTED_IMPLEMENTATION) && !defined(TINTED_IMPLEMENTATION)
#define TINTED_IMPLEMENTATION
#endif
#ifndef NK_TINTED_NO_SCHEMES
#include "vendor/tinted-c/include/tinted.h"

#define NK_TINTED_COUNT TINTED_COUNT
#define nuklear_tinted_schemes tinted_schemes
#else
/* Only the types, matching tinted-c, so the caller includes just the schemes it uses. */
#ifndef TINTED_C_COLOR_H__
#define TINTED_C_COLOR_H__
typedef struct tinted_color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} tinted_color;
#endif

#ifndef TINTED_C_SCHEME_H__
#define TINTED_C_SCHEME_H__
typedef struct tinted_scheme {
    const char *name;
    tinted_color base[24];
    unsigned char system;
} tinted_scheme;
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

NK_API void nuklear_tinted_set_scheme(struct nk_context* ctx, const tinted_scheme* scheme);
NK_API struct nk_color nuklear_tinted_color(const tinted_scheme* scheme, int index);

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
    table[NK_COLOR_SLIDER_CURSOR] = nuklear_tinted_color(scheme, 4);
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = nuklear_tinted_color(scheme, 5);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nuklear_tinted_color(scheme, 0x0D);

    table[NK_COLOR_PROPERTY] = nuklear_tinted_color(scheme, 1);

    table[NK_COLOR_EDIT] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_EDIT_CURSOR] = nuklear_tinted_color(scheme, 5);

    table[NK_COLOR_COMBO] = nuklear_tinted_color(scheme, 1);

    table[NK_COLOR_CHART] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_CHART_COLOR] = nuklear_tinted_color(scheme, 0x0D);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nuklear_tinted_color(scheme, 9);

    table[NK_COLOR_SCROLLBAR] = nuklear_tinted_color(scheme, 1);
    table[NK_COLOR_SCROLLBAR_CURSOR] = nuklear_tinted_color(scheme, 3);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nuklear_tinted_color(scheme, 4);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nuklear_tinted_color(scheme, 5);

    table[NK_COLOR_TAB_HEADER] = nuklear_tinted_color(scheme, 1);

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
