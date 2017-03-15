/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#ifndef HEADER_GUARD_TIME_CONSTANTS_H
#define HEADER_GUARD_TIME_CONSTANTS_H

#include <atomic>
#include <chrono>

namespace czipperz {
extern bool unlimited_fps;
extern std::chrono::microseconds frame_length;
const std::chrono::microseconds calc_length(1000000 / 1000);
static std::chrono::microseconds current_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch());
}

const int frame_width = 600, frame_height = 600;

extern std::atomic<bool> quit;
}

#endif
