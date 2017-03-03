#include "player.hh"

#include <algorithm>
#include "key_state.hh"
#include "frame.hh"
#include "level.hh"
#include "constants.hh"

namespace czipperz {
void player::update(
    const czipperz::frame& frame, const czipperz::key_state& state,
    const czipperz::key_state& previous_state) noexcept {
    const float ms = .3;
    dir = 0;
    if (state.a) {
        x -= ms;
        dir[2] = 1;
    }
    if (state.d) {
        x += ms;
        dir[3] = 1;
    }

    const auto y_before = y;
    y += velocity;

    velocity += .005;
    if (y + player::height >= czipperz::frame_height) {
        if (velocity > 2) {
            std::puts("Hit > 2");
        }
        velocity = 0;
        if (state.space && !previous_state.space) {
            velocity = -1.4;
        }
    } else {
        for (const czipperz::platform& platform :
             frame.level->platforms) {
            if (y + player::height >= platform.y &&
                y_before + player::height <= platform.y &&
                x + player::width >= platform.x_side(frame.side) &&
                x <= platform.x_side(frame.side) + platform.w) {

                platform_on = &platform;
                y = platform.y - player::height;
                if (velocity > 2) {
                    std::puts("Hit > 2");
                }
                velocity = 0;
                if (state.space && !previous_state.space) {
                    velocity = -1.4;
                }
                break;
            }
        }
    }

    if (y < 0) {
        y = 0;
        velocity = 0;
    }
    if (x < 0) {
        x = 0;
    }
    if (y + player::height > czipperz::frame_height) {
        y = czipperz::frame_height - player::height;
        velocity = 0;
    }
    if (x + player::width > czipperz::frame_width) {
        x = czipperz::frame_width - player::width;
    }
}

void player::turn(czipperz::side old, czipperz::side cur) noexcept {
    assert(platform_on);
    x -= platform_on->x_side(old);
    x += platform_on->x_side(cur);
}
}
