/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

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
