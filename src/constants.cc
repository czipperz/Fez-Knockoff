/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#include "constants.hh"

namespace czipperz {
bool unlimited_fps = true;
std::chrono::microseconds frame_length(1000000 / 100);

std::atomic<bool> quit(false);
}
