/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#ifndef HEADER_GUARD_KEY_HANDLER_H
#define HEADER_GUARD_KEY_HANDLER_H

#include <SDL2/SDL.h>
#include "key_state.hh"

namespace czipperz {
void key_handler(czipperz::key_state&, bool down, const SDL_Keysym&);
}

#endif
