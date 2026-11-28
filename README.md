# nuklear_tinted

[Tinted Theming](https://github.com/tinted-theming/home) styles for [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear). Over 500 Base16 and Base24 color styles to apply to your Nuklear GUI.

## Screenshot

![nuklear_tinted_demo Screenshot](demo/common/nuklear_tinted_demo.png)

## Setup

The scheme data comes from the [tinted-c](https://github.com/RobLoach/tinted-c) submodule, so clone recursively:

``` sh
git clone --recursive https://github.com/RobLoach/nuklear_tinted.git
# Or, in an existing clone:
git submodule update --init
```

## Usage

Include `nuklear.h` first, then define `NK_TINTED_IMPLEMENTATION` in exactly one source file before including `nuklear_tinted.h`:

``` c
#include "nuklear.h"

#define NK_TINTED_IMPLEMENTATION
#include "nuklear_tinted.h"

nuklear_tinted_set_scheme(ctx, &base16_tomorrow_night);
```

Every scheme is available as `nuklear_tinted_schemes`, with `NK_TINTED_COUNT` entries:

``` c
for (int i = 0; i < NK_TINTED_COUNT; i++) {
    printf("%s\n", nuklear_tinted_schemes[i]->name);
}
```

### Using only specific schemes

Define `NK_TINTED_NO_SCHEMES` to skip compiling all of the schemes, and include only the [tinted-c](https://github.com/RobLoach/tinted-c) headers you use. `nuklear_tinted_schemes` and `NK_TINTED_COUNT` aren't available in this mode.

``` c
#define NK_TINTED_IMPLEMENTATION
#define NK_TINTED_NO_SCHEMES
#include "nuklear_tinted.h"
#include "vendor/tinted-c/include/base16-dracula.h"

nuklear_tinted_set_scheme(ctx, &base16_dracula);
```

## Demos

``` sh
# SDL2
make -C demo/sdl
./demo/sdl/nuklear_tinted_sdl

# SDL3
make -C demo/sdl3_renderer
./demo/sdl3_renderer/nuklear_tinted_sdl3_renderer

# raylib
cmake -S demo/raylib -B build
cmake --build build
./build/nuklear_tinted_demo_raylib
```

## Dependencies

- C99, or C++20
- [tinted-c](https://github.com/RobLoach/tinted-c) C Headers for Base16 and Base24
- [Nuklear](https://github.com/Immediate-Mode-UI/Nuklear) GUI

## License

[MIT](LICENSE)
