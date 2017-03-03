#ifndef HEADER_GUARD_SIDE_H
#define HEADER_GUARD_SIDE_H

#include <assert.h>

namespace czipperz {
using side = int;
static void turn_right(side& _value) noexcept {
    if (_value == 0) {
        _value = 4;
    }
    --_value;
}
static void turn_left(side& _value) noexcept {
    ++_value;
    if (_value == 4) {
        _value = 0;
    }
}
namespace sides {
static const side LEFT = 3, RIGHT = 1, FRONT = 0, BACK = 2;
}
}

#endif
