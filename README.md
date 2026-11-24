# nuklear_base16

[Base16](https://github.com/tinted-theming/home) styles for [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear). Over 500 Base16 and Base24 color styles to apply to your Nuklear GUI.

## Screenshot

![nuklear_base16_demo Screenshot](demo/common/nuklear_base16_demo.png)

## Setup

The scheme data comes from the [tinted-c](https://github.com/RobLoach/tinted-c) submodule, so clone recursively:

``` sh
git clone --recursive https://github.com/RobLoach/nuklear_base16.git
# Or, in an existing clone:
git submodule update --init
```

## Usage

Include `nuklear.h` first, then define `NK_BASE16_IMPLEMENTATION` in exactly one source file before including `nuklear_base16.h`:

``` c
#include "nuklear.h"

#define NK_BASE16_IMPLEMENTATION
#include "nuklear_base16.h"

nuklear_base16_set_scheme(ctx, &base16_tomorrow_night);
```

Every scheme is available as `nuklear_base16_schemes`, with `NK_BASE16_COUNT` entries:

``` c
for (int i = 0; i < NK_BASE16_COUNT; i++) {
    printf("%s\n", nuklear_base16_schemes[i]->name);
}
```

## Demos

``` sh
# SDL2
make -C demo/sdl
./demo/sdl/nuklear_base16_sdl

# SDL3
make -C demo/sdl3_renderer
./demo/sdl3_renderer/nuklear_base16_sdl3_renderer

# raylib
cmake -S demo/raylib -B build
cmake --build build
./build/nuklear_base16_demo_raylib
```

## Dependencies

- C99, or C++20
- [tinted-c](https://github.com/RobLoach/tinted-c) C Headers for Base16 and Base24
- [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear) GUI

## License

[MIT](LICENSE)
