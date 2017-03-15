/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#include "menu.hh"

#include <assert.h>

#include "constants.hh"

namespace czipperz {
void menu::update(
    const czipperz::key_state& state,
    const czipperz::key_state& previous_state) {
    // Go to different menu items.
    assert(index >= 0 && index < 2);
    if (state.up && !previous_state.up ||
        state.w && !previous_state.w) {
        if (index > 0) {
            --index;
        }
    }
    if (state.down && !previous_state.down ||
        state.s && !previous_state.s) {
        if (index < 1) {
            ++index;
        }
    }

    if (state.enter) {
        switch (index) {
        case 0:
            break;
        case 1:
            czipperz::quit = true;
            return;
        }
    }
}
}
