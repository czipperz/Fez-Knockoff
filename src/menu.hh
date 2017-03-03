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
