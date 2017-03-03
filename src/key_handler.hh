#ifndef HEADER_GUARD_KEY_HANDLER_H
#define HEADER_GUARD_KEY_HANDLER_H

#include <SDL2/SDL.h>
#include "key_state.hh"

namespace czipperz {
void key_handler(czipperz::key_state&, bool down, const SDL_Keysym&);
}

#endif
