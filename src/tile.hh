/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

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
