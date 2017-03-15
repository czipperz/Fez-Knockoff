/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#include "key_state.hh"

namespace czipperz {
key_state::key_state() noexcept : w(0),
                                  a(0),
                                  s(0),
                                  d(0),
                                  up(0),
                                  down(0),
                                  left(0),
                                  right(0),
                                  j(0),
                                  l(0),
                                  space(0),
                                  escape(0),
                                  enter(0) {}
}
