/**
 * nuklear_base16: Base16 Color Themes for Nuklear
 * https://github.com/robloach/nuklear_base16
 *
 * @file nuklear_base16.h
 *
 * License:
 *
 * Copyright (c) 2024 Rob Loach (@RobLoach, https://robloach.net)
 *
 * This software is provided "as-is", without any express or implied warranty. In no event
 * will the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose, including commercial
 * applications, and to alter it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim that you
 * wrote the original software. If you use this software in a product, an acknowledgment
 * in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be misrepresented
 * as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef NUKLEAR_BASE16_H__
#define NUKLEAR_BASE16_H__

#define NK_BASE16_COUNT 266

#ifdef __cplusplus
extern "C" {
#endif

#include "vendor/base16-h/include/base16-tomorrow-night.h"

extern const base16_scheme* nuklear_base16_schemes[NK_BASE16_COUNT + 1];
NK_API void nuklear_base16_set_scheme(struct nk_context* ctx, const base16_scheme* scheme);
NK_API struct nk_color nuklear_base16_color(const base16_scheme* scheme, int index);

#ifdef __cplusplus
}
#endif

#endif

#if defined(NK_BASE16_IMPLEMENTATION) && !defined(NK_BASE16_HEADER_ONLY)
#ifndef NK_BASE16_IMPLEMENTATION_ONCE
#define NK_BASE16_IMPLEMENTATION_ONCE

#ifdef __cplusplus
extern "C" {
#endif

#define BASE16_IMPLEMENTATION
#include "vendor/base16-h/include/base16-3024.h"
#include "vendor/base16-h/include/base16-apathy.h"
#include "vendor/base16-h/include/base16-apprentice.h"
#include "vendor/base16-h/include/base16-ashes.h"
#include "vendor/base16-h/include/base16-atelier-cave.h"
#include "vendor/base16-h/include/base16-atelier-cave-light.h"
#include "vendor/base16-h/include/base16-atelier-dune.h"
#include "vendor/base16-h/include/base16-atelier-dune-light.h"
#include "vendor/base16-h/include/base16-atelier-estuary.h"
#include "vendor/base16-h/include/base16-atelier-estuary-light.h"
#include "vendor/base16-h/include/base16-atelier-forest.h"
#include "vendor/base16-h/include/base16-atelier-forest-light.h"
#include "vendor/base16-h/include/base16-atelier-heath.h"
#include "vendor/base16-h/include/base16-atelier-heath-light.h"
#include "vendor/base16-h/include/base16-atelier-lakeside.h"
#include "vendor/base16-h/include/base16-atelier-lakeside-light.h"
#include "vendor/base16-h/include/base16-atelier-plateau.h"
#include "vendor/base16-h/include/base16-atelier-plateau-light.h"
#include "vendor/base16-h/include/base16-atelier-savanna.h"
#include "vendor/base16-h/include/base16-atelier-savanna-light.h"
#include "vendor/base16-h/include/base16-atelier-seaside.h"
#include "vendor/base16-h/include/base16-atelier-seaside-light.h"
#include "vendor/base16-h/include/base16-atelier-sulphurpool.h"
#include "vendor/base16-h/include/base16-atelier-sulphurpool-light.h"
#include "vendor/base16-h/include/base16-atlas.h"
#include "vendor/base16-h/include/base16-ayu-dark.h"
#include "vendor/base16-h/include/base16-ayu-light.h"
#include "vendor/base16-h/include/base16-ayu-mirage.h"
#include "vendor/base16-h/include/base16-aztec.h"
#include "vendor/base16-h/include/base16-bespin.h"
#include "vendor/base16-h/include/base16-black-metal-bathory.h"
#include "vendor/base16-h/include/base16-black-metal-burzum.h"
#include "vendor/base16-h/include/base16-black-metal-dark-funeral.h"
#include "vendor/base16-h/include/base16-black-metal-gorgoroth.h"
#include "vendor/base16-h/include/base16-black-metal.h"
#include "vendor/base16-h/include/base16-black-metal-immortal.h"
#include "vendor/base16-h/include/base16-black-metal-khold.h"
#include "vendor/base16-h/include/base16-black-metal-marduk.h"
#include "vendor/base16-h/include/base16-black-metal-mayhem.h"
#include "vendor/base16-h/include/base16-black-metal-nile.h"
#include "vendor/base16-h/include/base16-black-metal-venom.h"
#include "vendor/base16-h/include/base16-blueforest.h"
#include "vendor/base16-h/include/base16-blueish.h"
#include "vendor/base16-h/include/base16-brewer.h"
#include "vendor/base16-h/include/base16-bright.h"
#include "vendor/base16-h/include/base16-brogrammer.h"
#include "vendor/base16-h/include/base16-brushtrees-dark.h"
#include "vendor/base16-h/include/base16-brushtrees.h"
#include "vendor/base16-h/include/base16-caroline.h"
#include "vendor/base16-h/include/base16-catppuccin-frappe.h"
#include "vendor/base16-h/include/base16-catppuccin-latte.h"
#include "vendor/base16-h/include/base16-catppuccin-macchiato.h"
#include "vendor/base16-h/include/base16-catppuccin-mocha.h"
#include "vendor/base16-h/include/base16-chalk.h"
#include "vendor/base16-h/include/base16-circus.h"
#include "vendor/base16-h/include/base16-classic-dark.h"
#include "vendor/base16-h/include/base16-classic-light.h"
#include "vendor/base16-h/include/base16-codeschool.h"
#include "vendor/base16-h/include/base16-colors.h"
#include "vendor/base16-h/include/base16-cupcake.h"
#include "vendor/base16-h/include/base16-cupertino.h"
#include "vendor/base16-h/include/base16-danqing.h"
#include "vendor/base16-h/include/base16-danqing-light.h"
#include "vendor/base16-h/include/base16-da-one-black.h"
#include "vendor/base16-h/include/base16-da-one-gray.h"
#include "vendor/base16-h/include/base16-da-one-ocean.h"
#include "vendor/base16-h/include/base16-da-one-paper.h"
#include "vendor/base16-h/include/base16-da-one-sea.h"
#include "vendor/base16-h/include/base16-da-one-white.h"
#include "vendor/base16-h/include/base16-darcula.h"
#include "vendor/base16-h/include/base16-darkmoss.h"
#include "vendor/base16-h/include/base16-darktooth.h"
#include "vendor/base16-h/include/base16-darkviolet.h"
#include "vendor/base16-h/include/base16-decaf.h"
#include "vendor/base16-h/include/base16-default-dark.h"
#include "vendor/base16-h/include/base16-default-light.h"
#include "vendor/base16-h/include/base16-dirtysea.h"
#include "vendor/base16-h/include/base16-dracula.h"
#include "vendor/base16-h/include/base16-edge-dark.h"
#include "vendor/base16-h/include/base16-edge-light.h"
#include "vendor/base16-h/include/base16-eighties.h"
#include "vendor/base16-h/include/base16-embers.h"
#include "vendor/base16-h/include/base16-embers-light.h"
#include "vendor/base16-h/include/base16-emil.h"
#include "vendor/base16-h/include/base16-equilibrium-dark.h"
#include "vendor/base16-h/include/base16-equilibrium-gray-dark.h"
#include "vendor/base16-h/include/base16-equilibrium-gray-light.h"
#include "vendor/base16-h/include/base16-equilibrium-light.h"
#include "vendor/base16-h/include/base16-eris.h"
#include "vendor/base16-h/include/base16-espresso.h"
#include "vendor/base16-h/include/base16-eva-dim.h"
#include "vendor/base16-h/include/base16-eva.h"
#include "vendor/base16-h/include/base16-evenok-dark.h"
#include "vendor/base16-h/include/base16-everforest-dark-hard.h"
#include "vendor/base16-h/include/base16-everforest.h"
#include "vendor/base16-h/include/base16-flat.h"
#include "vendor/base16-h/include/base16-framer.h"
#include "vendor/base16-h/include/base16-fruit-soda.h"
#include "vendor/base16-h/include/base16-gigavolt.h"
#include "vendor/base16-h/include/base16-github.h"
#include "vendor/base16-h/include/base16-google-dark.h"
#include "vendor/base16-h/include/base16-google-light.h"
#include "vendor/base16-h/include/base16-gotham.h"
#include "vendor/base16-h/include/base16-grayscale-dark.h"
#include "vendor/base16-h/include/base16-grayscale-light.h"
#include "vendor/base16-h/include/base16-greenscreen.h"
#include "vendor/base16-h/include/base16-gruber.h"
#include "vendor/base16-h/include/base16-gruvbox-dark-hard.h"
#include "vendor/base16-h/include/base16-gruvbox-dark-medium.h"
#include "vendor/base16-h/include/base16-gruvbox-dark-pale.h"
#include "vendor/base16-h/include/base16-gruvbox-dark-soft.h"
#include "vendor/base16-h/include/base16-gruvbox-light-hard.h"
#include "vendor/base16-h/include/base16-gruvbox-light-medium.h"
#include "vendor/base16-h/include/base16-gruvbox-light-soft.h"
#include "vendor/base16-h/include/base16-gruvbox-material-dark-hard.h"
#include "vendor/base16-h/include/base16-gruvbox-material-dark-medium.h"
#include "vendor/base16-h/include/base16-gruvbox-material-dark-soft.h"
#include "vendor/base16-h/include/base16-gruvbox-material-light-hard.h"
#include "vendor/base16-h/include/base16-gruvbox-material-light-medium.h"
#include "vendor/base16-h/include/base16-gruvbox-material-light-soft.h"
#include "vendor/base16-h/include/base16-hardcore.h"
#include "vendor/base16-h/include/base16-harmonic16-dark.h"
#include "vendor/base16-h/include/base16-harmonic16-light.h"
#include "vendor/base16-h/include/base16-heetch.h"
#include "vendor/base16-h/include/base16-heetch-light.h"
#include "vendor/base16-h/include/base16-helios.h"
#include "vendor/base16-h/include/base16-hopscotch.h"
#include "vendor/base16-h/include/base16-horizon-dark.h"
#include "vendor/base16-h/include/base16-horizon-light.h"
#include "vendor/base16-h/include/base16-horizon-terminal-dark.h"
#include "vendor/base16-h/include/base16-horizon-terminal-light.h"
#include "vendor/base16-h/include/base16-humanoid-dark.h"
#include "vendor/base16-h/include/base16-humanoid-light.h"
#include "vendor/base16-h/include/base16-ia-dark.h"
#include "vendor/base16-h/include/base16-ia-light.h"
#include "vendor/base16-h/include/base16-icy.h"
#include "vendor/base16-h/include/base16-irblack.h"
#include "vendor/base16-h/include/base16-isotope.h"
#include "vendor/base16-h/include/base16-jabuti.h"
#include "vendor/base16-h/include/base16-kanagawa.h"
#include "vendor/base16-h/include/base16-katy.h"
#include "vendor/base16-h/include/base16-kimber.h"
#include "vendor/base16-h/include/base16-lime.h"
#include "vendor/base16-h/include/base16-macintosh.h"
#include "vendor/base16-h/include/base16-marrakesh.h"
#include "vendor/base16-h/include/base16-materia.h"
#include "vendor/base16-h/include/base16-material-darker.h"
#include "vendor/base16-h/include/base16-material.h"
#include "vendor/base16-h/include/base16-material-lighter.h"
#include "vendor/base16-h/include/base16-material-palenight.h"
#include "vendor/base16-h/include/base16-material-vivid.h"
#include "vendor/base16-h/include/base16-measured-dark.h"
#include "vendor/base16-h/include/base16-measured-light.h"
#include "vendor/base16-h/include/base16-mellow-purple.h"
#include "vendor/base16-h/include/base16-mexico-light.h"
#include "vendor/base16-h/include/base16-mocha.h"
#include "vendor/base16-h/include/base16-monokai.h"
#include "vendor/base16-h/include/base16-moonlight.h"
#include "vendor/base16-h/include/base16-mountain.h"
#include "vendor/base16-h/include/base16-nebula.h"
#include "vendor/base16-h/include/base16-nord.h"
#include "vendor/base16-h/include/base16-nord-light.h"
#include "vendor/base16-h/include/base16-nova.h"
#include "vendor/base16-h/include/base16-ocean.h"
#include "vendor/base16-h/include/base16-oceanicnext.h"
#include "vendor/base16-h/include/base16-onedark.h"
#include "vendor/base16-h/include/base16-one-light.h"
#include "vendor/base16-h/include/base16-outrun-dark.h"
#include "vendor/base16-h/include/base16-oxocarbon-dark.h"
#include "vendor/base16-h/include/base16-oxocarbon-light.h"
#include "vendor/base16-h/include/base16-pandora.h"
#include "vendor/base16-h/include/base16-papercolor-dark.h"
#include "vendor/base16-h/include/base16-papercolor-light.h"
#include "vendor/base16-h/include/base16-paraiso.h"
#include "vendor/base16-h/include/base16-pasque.h"
#include "vendor/base16-h/include/base16-phd.h"
#include "vendor/base16-h/include/base16-pico.h"
#include "vendor/base16-h/include/base16-pinky.h"
#include "vendor/base16-h/include/base16-pop.h"
#include "vendor/base16-h/include/base16-porple.h"
#include "vendor/base16-h/include/base16-precious-dark-eleven.h"
#include "vendor/base16-h/include/base16-precious-dark-fifteen.h"
#include "vendor/base16-h/include/base16-precious-light-warm.h"
#include "vendor/base16-h/include/base16-precious-light-white.h"
#include "vendor/base16-h/include/base16-primer-dark-dimmed.h"
#include "vendor/base16-h/include/base16-primer-dark.h"
#include "vendor/base16-h/include/base16-primer-light.h"
#include "vendor/base16-h/include/base16-purpledream.h"
#include "vendor/base16-h/include/base16-qualia.h"
#include "vendor/base16-h/include/base16-railscasts.h"
#include "vendor/base16-h/include/base16-rebecca.h"
#include "vendor/base16-h/include/base16-rose-pine-dawn.h"
#include "vendor/base16-h/include/base16-rose-pine.h"
#include "vendor/base16-h/include/base16-rose-pine-moon.h"
#include "vendor/base16-h/include/base16-saga.h"
#include "vendor/base16-h/include/base16-sagelight.h"
#include "vendor/base16-h/include/base16-sakura.h"
#include "vendor/base16-h/include/base16-sandcastle.h"
#include "vendor/base16-h/include/base16-selenized-black.h"
#include "vendor/base16-h/include/base16-selenized-dark.h"
#include "vendor/base16-h/include/base16-selenized-light.h"
#include "vendor/base16-h/include/base16-selenized-white.h"
#include "vendor/base16-h/include/base16-seti.h"
#include "vendor/base16-h/include/base16-shadesmear-dark.h"
#include "vendor/base16-h/include/base16-shadesmear-light.h"
#include "vendor/base16-h/include/base16-shades-of-purple.h"
#include "vendor/base16-h/include/base16-shapeshifter.h"
#include "vendor/base16-h/include/base16-silk-dark.h"
#include "vendor/base16-h/include/base16-silk-light.h"
#include "vendor/base16-h/include/base16-snazzy.h"
#include "vendor/base16-h/include/base16-solarflare.h"
#include "vendor/base16-h/include/base16-solarflare-light.h"
#include "vendor/base16-h/include/base16-solarized-dark.h"
#include "vendor/base16-h/include/base16-solarized-light.h"
#include "vendor/base16-h/include/base16-spaceduck.h"
#include "vendor/base16-h/include/base16-spacemacs.h"
#include "vendor/base16-h/include/base16-sparky.h"
#include "vendor/base16-h/include/base16-standardized-dark.h"
#include "vendor/base16-h/include/base16-standardized-light.h"
#include "vendor/base16-h/include/base16-stella.h"
#include "vendor/base16-h/include/base16-still-alive.h"
#include "vendor/base16-h/include/base16-summercamp.h"
#include "vendor/base16-h/include/base16-summerfruit-dark.h"
#include "vendor/base16-h/include/base16-summerfruit-light.h"
#include "vendor/base16-h/include/base16-synth-midnight-dark.h"
#include "vendor/base16-h/include/base16-synth-midnight-light.h"
#include "vendor/base16-h/include/base16-tango.h"
#include "vendor/base16-h/include/base16-tarot.h"
#include "vendor/base16-h/include/base16-tender.h"
#include "vendor/base16-h/include/base16-tokyo-city-dark.h"
#include "vendor/base16-h/include/base16-tokyo-city-light.h"
#include "vendor/base16-h/include/base16-tokyo-city-terminal-dark.h"
#include "vendor/base16-h/include/base16-tokyo-city-terminal-light.h"
#include "vendor/base16-h/include/base16-tokyodark.h"
#include "vendor/base16-h/include/base16-tokyodark-terminal.h"
#include "vendor/base16-h/include/base16-tokyo-night-dark.h"
#include "vendor/base16-h/include/base16-tokyo-night-light.h"
#include "vendor/base16-h/include/base16-tokyo-night-moon.h"
#include "vendor/base16-h/include/base16-tokyo-night-storm.h"
#include "vendor/base16-h/include/base16-tokyo-night-terminal-dark.h"
#include "vendor/base16-h/include/base16-tokyo-night-terminal-light.h"
#include "vendor/base16-h/include/base16-tokyo-night-terminal-storm.h"
#include "vendor/base16-h/include/base16-tomorrow.h"
#include "vendor/base16-h/include/base16-tomorrow-night-eighties.h"
#include "vendor/base16-h/include/base16-tomorrow-night.h"
#include "vendor/base16-h/include/base16-tube.h"
#include "vendor/base16-h/include/base16-twilight.h"
#include "vendor/base16-h/include/base16-unikitty-dark.h"
#include "vendor/base16-h/include/base16-unikitty-light.h"
#include "vendor/base16-h/include/base16-unikitty-reversible.h"
#include "vendor/base16-h/include/base16-uwunicorn.h"
#include "vendor/base16-h/include/base16-vesper.h"
#include "vendor/base16-h/include/base16-vice.h"
#include "vendor/base16-h/include/base16-vulcan.h"
#include "vendor/base16-h/include/base16-windows-10.h"
#include "vendor/base16-h/include/base16-windows-10-light.h"
#include "vendor/base16-h/include/base16-windows-95.h"
#include "vendor/base16-h/include/base16-windows-95-light.h"
#include "vendor/base16-h/include/base16-windows-highcontrast.h"
#include "vendor/base16-h/include/base16-windows-highcontrast-light.h"
#include "vendor/base16-h/include/base16-windows-nt.h"
#include "vendor/base16-h/include/base16-windows-nt-light.h"
#include "vendor/base16-h/include/base16-woodland.h"
#include "vendor/base16-h/include/base16-xcode-dusk.h"
#include "vendor/base16-h/include/base16-zenbones.h"
#include "vendor/base16-h/include/base16-zenburn.h"

const base16_scheme* nuklear_base16_schemes[NK_BASE16_COUNT + 1] = {
    &base16_3024,
    &base16_apathy,
    &base16_apprentice,
    &base16_ashes,
    &base16_atelier_cave,
    &base16_atelier_cave_light,
    &base16_atelier_dune,
    &base16_atelier_dune_light,
    &base16_atelier_estuary,
    &base16_atelier_estuary_light,
    &base16_atelier_forest,
    &base16_atelier_forest_light,
    &base16_atelier_heath,
    &base16_atelier_heath_light,
    &base16_atelier_lakeside,
    &base16_atelier_lakeside_light,
    &base16_atelier_plateau,
    &base16_atelier_plateau_light,
    &base16_atelier_savanna,
    &base16_atelier_savanna_light,
    &base16_atelier_seaside,
    &base16_atelier_seaside_light,
    &base16_atelier_sulphurpool,
    &base16_atelier_sulphurpool_light,
    &base16_atlas,
    &base16_ayu_dark,
    &base16_ayu_light,
    &base16_ayu_mirage,
    &base16_aztec,
    &base16_bespin,
    &base16_black_metal_bathory,
    &base16_black_metal_burzum,
    &base16_black_metal_dark_funeral,
    &base16_black_metal_gorgoroth,
    &base16_black_metal,
    &base16_black_metal_immortal,
    &base16_black_metal_khold,
    &base16_black_metal_marduk,
    &base16_black_metal_mayhem,
    &base16_black_metal_nile,
    &base16_black_metal_venom,
    &base16_blueforest,
    &base16_blueish,
    &base16_brewer,
    &base16_bright,
    &base16_brogrammer,
    &base16_brushtrees_dark,
    &base16_brushtrees,
    &base16_caroline,
    &base16_catppuccin_frappe,
    &base16_catppuccin_latte,
    &base16_catppuccin_macchiato,
    &base16_catppuccin_mocha,
    &base16_chalk,
    &base16_circus,
    &base16_classic_dark,
    &base16_classic_light,
    &base16_codeschool,
    &base16_colors,
    &base16_cupcake,
    &base16_cupertino,
    &base16_danqing,
    &base16_danqing_light,
    &base16_da_one_black,
    &base16_da_one_gray,
    &base16_da_one_ocean,
    &base16_da_one_paper,
    &base16_da_one_sea,
    &base16_da_one_white,
    &base16_darcula,
    &base16_darkmoss,
    &base16_darktooth,
    &base16_darkviolet,
    &base16_decaf,
    &base16_default_dark,
    &base16_default_light,
    &base16_dirtysea,
    &base16_dracula,
    &base16_edge_dark,
    &base16_edge_light,
    &base16_eighties,
    &base16_embers,
    &base16_embers_light,
    &base16_emil,
    &base16_equilibrium_dark,
    &base16_equilibrium_gray_dark,
    &base16_equilibrium_gray_light,
    &base16_equilibrium_light,
    &base16_eris,
    &base16_espresso,
    &base16_eva_dim,
    &base16_eva,
    &base16_evenok_dark,
    &base16_everforest_dark_hard,
    &base16_everforest,
    &base16_flat,
    &base16_framer,
    &base16_fruit_soda,
    &base16_gigavolt,
    &base16_github,
    &base16_google_dark,
    &base16_google_light,
    &base16_gotham,
    &base16_grayscale_dark,
    &base16_grayscale_light,
    &base16_greenscreen,
    &base16_gruber,
    &base16_gruvbox_dark_hard,
    &base16_gruvbox_dark_medium,
    &base16_gruvbox_dark_pale,
    &base16_gruvbox_dark_soft,
    &base16_gruvbox_light_hard,
    &base16_gruvbox_light_medium,
    &base16_gruvbox_light_soft,
    &base16_gruvbox_material_dark_hard,
    &base16_gruvbox_material_dark_medium,
    &base16_gruvbox_material_dark_soft,
    &base16_gruvbox_material_light_hard,
    &base16_gruvbox_material_light_medium,
    &base16_gruvbox_material_light_soft,
    &base16_hardcore,
    &base16_harmonic16_dark,
    &base16_harmonic16_light,
    &base16_heetch,
    &base16_heetch_light,
    &base16_helios,
    &base16_hopscotch,
    &base16_horizon_dark,
    &base16_horizon_light,
    &base16_horizon_terminal_dark,
    &base16_horizon_terminal_light,
    &base16_humanoid_dark,
    &base16_humanoid_light,
    &base16_ia_dark,
    &base16_ia_light,
    &base16_icy,
    &base16_irblack,
    &base16_isotope,
    &base16_jabuti,
    &base16_kanagawa,
    &base16_katy,
    &base16_kimber,
    &base16_lime,
    &base16_macintosh,
    &base16_marrakesh,
    &base16_materia,
    &base16_material_darker,
    &base16_material,
    &base16_material_lighter,
    &base16_material_palenight,
    &base16_material_vivid,
    &base16_measured_dark,
    &base16_measured_light,
    &base16_mellow_purple,
    &base16_mexico_light,
    &base16_mocha,
    &base16_monokai,
    &base16_moonlight,
    &base16_mountain,
    &base16_nebula,
    &base16_nord,
    &base16_nord_light,
    &base16_nova,
    &base16_ocean,
    &base16_oceanicnext,
    &base16_onedark,
    &base16_one_light,
    &base16_outrun_dark,
    &base16_oxocarbon_dark,
    &base16_oxocarbon_light,
    &base16_pandora,
    &base16_papercolor_dark,
    &base16_papercolor_light,
    &base16_paraiso,
    &base16_pasque,
    &base16_phd,
    &base16_pico,
    &base16_pinky,
    &base16_pop,
    &base16_porple,
    &base16_precious_dark_eleven,
    &base16_precious_dark_fifteen,
    &base16_precious_light_warm,
    &base16_precious_light_white,
    &base16_primer_dark_dimmed,
    &base16_primer_dark,
    &base16_primer_light,
    &base16_purpledream,
    &base16_qualia,
    &base16_railscasts,
    &base16_rebecca,
    &base16_rose_pine_dawn,
    &base16_rose_pine,
    &base16_rose_pine_moon,
    &base16_saga,
    &base16_sagelight,
    &base16_sakura,
    &base16_sandcastle,
    &base16_selenized_black,
    &base16_selenized_dark,
    &base16_selenized_light,
    &base16_selenized_white,
    &base16_seti,
    &base16_shadesmear_dark,
    &base16_shadesmear_light,
    &base16_shades_of_purple,
    &base16_shapeshifter,
    &base16_silk_dark,
    &base16_silk_light,
    &base16_snazzy,
    &base16_solarflare,
    &base16_solarflare_light,
    &base16_solarized_dark,
    &base16_solarized_light,
    &base16_spaceduck,
    &base16_spacemacs,
    &base16_sparky,
    &base16_standardized_dark,
    &base16_standardized_light,
    &base16_stella,
    &base16_still_alive,
    &base16_summercamp,
    &base16_summerfruit_dark,
    &base16_summerfruit_light,
    &base16_synth_midnight_dark,
    &base16_synth_midnight_light,
    &base16_tango,
    &base16_tarot,
    &base16_tender,
    &base16_tokyo_city_dark,
    &base16_tokyo_city_light,
    &base16_tokyo_city_terminal_dark,
    &base16_tokyo_city_terminal_light,
    &base16_tokyodark,
    &base16_tokyodark_terminal,
    &base16_tokyo_night_dark,
    &base16_tokyo_night_light,
    &base16_tokyo_night_moon,
    &base16_tokyo_night_storm,
    &base16_tokyo_night_terminal_dark,
    &base16_tokyo_night_terminal_light,
    &base16_tokyo_night_terminal_storm,
    &base16_tomorrow,
    &base16_tomorrow_night_eighties,
    &base16_tomorrow_night,
    &base16_tube,
    &base16_twilight,
    &base16_unikitty_dark,
    &base16_unikitty_light,
    &base16_unikitty_reversible,
    &base16_uwunicorn,
    &base16_vesper,
    &base16_vice,
    &base16_vulcan,
    &base16_windows_10,
    &base16_windows_10_light,
    &base16_windows_95,
    &base16_windows_95_light,
    &base16_windows_highcontrast,
    &base16_windows_highcontrast_light,
    &base16_windows_nt,
    &base16_windows_nt_light,
    &base16_woodland,
    &base16_xcode_dusk,
    &base16_zenbones,
    &base16_zenburn,

    NULL
};

NK_API struct nk_color nuklear_base16_color(const base16_scheme* scheme, int index) {
    return nk_rgba(scheme->base[index].r, scheme->base[index].g, scheme->base[index].b, 255);
}

NK_API void nuklear_base16_set_scheme(struct nk_context* ctx, const base16_scheme* scheme) {
    if (scheme == NULL) {
        return;
    }
    struct nk_color table[NK_COLOR_COUNT];

    table[NK_COLOR_TEXT] = nuklear_base16_color(scheme, 5);
    table[NK_COLOR_WINDOW] = nuklear_base16_color(scheme, 0);
    table[NK_COLOR_HEADER] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_BORDER] = nuklear_base16_color(scheme, 2);
    
    table[NK_COLOR_BUTTON] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_BUTTON_HOVER] = nuklear_base16_color(scheme, 2);
    table[NK_COLOR_BUTTON_ACTIVE] = nuklear_base16_color(scheme, 3);

    table[NK_COLOR_TOGGLE] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_TOGGLE_HOVER] = nuklear_base16_color(scheme, 2);
    table[NK_COLOR_TOGGLE_CURSOR] = nuklear_base16_color(scheme, 3);

    table[NK_COLOR_SELECT] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_SELECT_ACTIVE] = nuklear_base16_color(scheme, 2);

    table[NK_COLOR_SLIDER] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_SLIDER_CURSOR] = nuklear_base16_color(scheme, 2);
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = nuklear_base16_color(scheme, 3);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nuklear_base16_color(scheme, 4);

    table[NK_COLOR_PROPERTY] = nuklear_base16_color(scheme, 1);

    table[NK_COLOR_EDIT] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_EDIT_CURSOR] = nuklear_base16_color(scheme, 2);

    table[NK_COLOR_COMBO] = nuklear_base16_color(scheme, 1);

    table[NK_COLOR_CHART] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_CHART_COLOR] = nuklear_base16_color(scheme, 5);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nuklear_base16_color(scheme, 8);

    table[NK_COLOR_SCROLLBAR] = nuklear_base16_color(scheme, 1);
    table[NK_COLOR_SCROLLBAR_CURSOR] = nuklear_base16_color(scheme, 2);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nuklear_base16_color(scheme, 3);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nuklear_base16_color(scheme, 4);

    table[NK_COLOR_TAB_HEADER] = nuklear_base16_color(scheme, 1);

    nk_style_from_table(ctx, table);
}

#ifdef __cplusplus
}
#endif

#endif  // NK_BASE16_IMPLEMENTATION_ONCE
#endif  // NK_BASE16_IMPLEMENTATION