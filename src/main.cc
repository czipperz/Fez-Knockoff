#include <chrono>
#include <cstdio>
#include <thread>

#include "sdl/initializer.hh"
#include "sdl/window.hh"

#include "renderer_thread.hh"
#include "calculator_thread.hh"

extern "C" int main(int argc, char** argv) {
    sdl::initializer sdl;
    sdl::window window("Fez Knockoff",
#ifdef NDEBUG
                       SDL_WINDOWPOS_CENTERED,
#else
                       200,
#endif
                       SDL_WINDOWPOS_CENTERED, 600, 600,
                       SDL_WINDOW_SHOWN);

    sdl::renderer renderer(window, -1, 0);

    std::thread thread(czipperz::calculator_thread, &renderer);
    czipperz::renderer_thread(window, renderer);

    return 0;
}
