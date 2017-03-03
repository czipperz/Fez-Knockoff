#ifndef HEADER_GUARD_CALCULATOR_THREAD_H
#define HEADER_GUARD_CALCULATOR_THREAD_H

#include <atomic>
#include "frame.hh"

namespace czipperz {
extern std::atomic<const frame*> frame_to_render;

void calculator_thread(sdl::renderer*);
}

#endif
