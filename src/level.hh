#ifndef HEADER_GUARD_LEVEL_H
#define HEADER_GUARD_LEVEL_H

#include <vector>

#include "sdl/texture.hh"

#include "tile.hh"
#include "entity.hh"

namespace czipperz {
struct level {
    sdl::texture textures[4];
    std::vector<czipperz::platform> platforms;
    std::vector<czipperz::door> doors;

    level(sdl::texture front, sdl::texture right, sdl::texture back,
          sdl::texture left)
        : textures{std::move(front), std::move(right),
                   std::move(back), std::move(left)} {}
};
}

#endif
