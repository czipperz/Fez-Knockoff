/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

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
