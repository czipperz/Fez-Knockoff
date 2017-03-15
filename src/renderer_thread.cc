/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright (c) 2017 Chris Gregory czipperz@gmail.com
 */

#include "renderer_thread.hh"

#include "sdl/event.hh"
#include "sdl/renderer.hh"
#include "sdl/texture.hh"

#include <chrono>
#include <cstdio>
#include <thread>

#include "calculator_thread.hh"
#include "render.hh"
#include "constants.hh"

namespace czipperz {
void renderer_thread(sdl::window& window, sdl::renderer& renderer) {
    sdl::texture texture(renderer, SDL_PIXELFORMAT_RGBA8888,
                         SDL_TEXTUREACCESS_TARGET, window.width(),
                         window.height());

    std::chrono::microseconds start_time = czipperz::current_time(),
                              previous_sec_time =
                                  czipperz::current_time();
    int frames = 0;
    while (!czipperz::quit) {
        // Get the frame
        const frame* frame;
        while (!(frame = czipperz::frame_to_render.load())) {
            if (czipperz::quit) {
                return;
            }
        }

        sdl::pump_events();

        // Actually render
        render(renderer, texture, *frame);

        if (!unlimited_fps) {
            // Sleep until next frame
            const std::chrono::microseconds current_time =
                czipperz::current_time();
            if (czipperz::frame_length + start_time > current_time) {
                std::this_thread::sleep_for(czipperz::frame_length +
                                            start_time -
                                            current_time);
            } else {
#ifndef NDEBUG
                std::puts("Skipped render frame");
#endif
            }
            start_time += czipperz::frame_length;
        }

#ifndef NDEBUG
        if (czipperz::current_time() >
            previous_sec_time + std::chrono::seconds(1)) {
            std::printf("%d\t", frames);
            std::fflush(stdout);
            previous_sec_time += std::chrono::seconds(1);
            frames = 0;
        } else {
            ++frames;
        }
#endif

        // Request a new frame
        frame_to_render = nullptr;
    }
}
}
