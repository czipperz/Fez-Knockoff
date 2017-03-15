/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#include "key_handler.hh"

namespace czipperz {
void key_handler(czipperz::key_state& state, bool down,
                 const SDL_Keysym& keysym) {
    switch (keysym.sym) {
    case SDLK_w:
        state.w = down;
        break;
    case SDLK_a:
        state.a = down;
        break;
    case SDLK_s:
        state.s = down;
        break;
    case SDLK_d:
        state.d = down;
        break;
    case SDLK_UP:
        state.up = down;
        break;
    case SDLK_DOWN:
        state.down = down;
        break;
    case SDLK_LEFT:
        state.left = down;
        break;
    case SDLK_RIGHT:
        state.right = down;
        break;
    case SDLK_j:
        state.j = down;
        break;
    case SDLK_l:
        state.l = down;
        break;
    case SDLK_SPACE:
        state.space = down;
        break;
    case SDLK_ESCAPE:
        state.escape = down;
        break;
    case SDLK_RETURN:
        state.enter = down;
        break;
    }
}
}
