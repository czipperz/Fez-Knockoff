#ifndef HEADER_GUARD_PLAYER_H
#define HEADER_GUARD_PLAYER_H

#include <bitset>

#include "key_state.hh"
#include "side.hh"

namespace czipperz {
class frame;
class platform;
struct player {
    float y = 0, x = 0;
    float velocity = 0;
    const czipperz::platform* platform_on = nullptr;
    std::bitset<4> dir;

    void update(const czipperz::frame& frame,
                const czipperz::key_state& this_state,
                const czipperz::key_state& previous_state) noexcept;
    void turn(const side old, const side current) noexcept;

    static const int width = 100, height = 100;
};
}

#endif
