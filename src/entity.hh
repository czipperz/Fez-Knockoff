#ifndef HEADER_GUARD_ENTITY_H
#define HEADER_GUARD_ENTITY_H

#include "sdl/rect.hh"

#include "side.hh"

namespace czipperz {
struct entity {
    struct side {
        int x;
        int depth;
    } sides[2];
    int y, w, h;

    sdl::rect get_side(czipperz::side s) const noexcept {
        return sdl::rect_of(x_side(s), y, w, h);
    }
    int x_side(czipperz::side s) const noexcept {
        assert(s >= 0 && s < 4);
        if (s >= 2) {
            return 600 - sides[s - 2].x - w;
        } else {
            return sides[s].x;
        }
    }

protected:
    entity() noexcept = default;
    entity(const side& y_axis, const side& x_axis, int y, int w,
           int h) noexcept : sides{y_axis, x_axis},
                             y(y),
                             w(w),
                             h(h) {}
};

struct door : entity {
    int level_id;
};
struct platform : entity {
    platform() noexcept = default;
    platform(const side& y_axis, const side& x_axis, int y, int w,
             int h) noexcept : entity(y_axis, x_axis, y, w, h) {}
};
}

#endif
