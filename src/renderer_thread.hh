#ifndef HEADER_GUARD_RENDERER_THREAD_H
#define HEADER_GUARD_RENDERER_THREAD_H

#include "sdl/window.hh"

namespace czipperz {
void renderer_thread(sdl::window&, sdl::renderer& window_renderer);
}

#endif
