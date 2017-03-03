#ifndef HEADER_GUARD_KEY_STATE_H
#define HEADER_GUARD_KEY_STATE_H

#include <bitset>

namespace czipperz {
struct key_state {
    bool w : 1, a : 1, s : 1, d : 1;
    bool up : 1, down : 1, left : 1, right : 1;
    bool j : 1, l : 1;
    bool space : 1, escape : 1, enter : 1;

    key_state() noexcept;
};
}

#endif
