/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#ifndef HEADER_GUARD_FRAME_H
#define HEADER_GUARD_FRAME_H

#include "player.hh"
#include "level.hh"
#include "menu.hh"
#include "side.hh"

namespace czipperz {
struct frame {
    czipperz::player player;
    czipperz::menu menu;
    const czipperz::level* level = nullptr;
    bool draw_menu = false;
    czipperz::side side = czipperz::sides::FRONT;
    int x_offset, y_offset;

    explicit frame() noexcept = default;
};
}

#endif
