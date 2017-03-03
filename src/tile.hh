#ifndef HEADER_GUARD_TILE_H
#define HEADER_GUARD_TILE_H

#include <SDL2/SDL.h>

namespace czipperz {
struct tile {
    Uint8 r, g, b, a;

    tile() noexcept : r(0), g(0), b(0), a(255) {}
};
}

#endif
