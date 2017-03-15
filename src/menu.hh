/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#ifndef HEADER_GUARD_MENU_H
#define HEADER_GUARD_MENU_H

#include "key_state.hh"

namespace czipperz {
struct menu {
    int index = 0;

    void update(const czipperz::key_state& this_state,
                const czipperz::key_state& previous_state);
};
}

#endif
