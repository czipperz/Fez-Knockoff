#include "calculator_thread.hh"

#include "sdl/event.hh"
#include "sdl/img.hh"

#include <chrono>
#include <cstdio>
#include <thread>

#include "entity.hh"
#include "key_state.hh"
#include "key_handler.hh"
#include "constants.hh"

namespace czipperz {
std::atomic<const czipperz::frame*> frame_to_render(nullptr);

static void
send_to_render(czipperz::frame*& frame,
               czipperz::frame*& previous_frame) {
    /* Update frame_to_render */
    const czipperz::frame* expected_frame = nullptr;
    // If done rendering, give renderer another frame
    czipperz::frame_to_render.compare_exchange_strong(expected_frame,
                                                      frame);
    // If renderer requested another frame, swap which one we write
    // to.
    if (!expected_frame) {
        std::swap(frame, previous_frame);
        *frame = *previous_frame;
    }
}

static void handle_key_events(czipperz::key_state& key_state) {
    // Key events
    for (sdl::event event; sdl::get_event(&event);) {
        switch (event.type) {
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            // Handle the keys
            czipperz::key_handler(key_state,
                                    event.type == SDL_KEYDOWN,
                                    event.key.keysym);
            break;
        case SDL_QUIT:
            czipperz::quit = true;
            break;
        }
    }
}

static void
calculate(czipperz::frame& frame, czipperz::key_state& key_state,
          czipperz::key_state& previous_key_state) {
    // Draw menu
    if (key_state.escape && !previous_key_state.escape) {
        frame.draw_menu = !frame.draw_menu;
        frame.menu.index = 0;
    }

    // Update side
    if (key_state.j && !previous_key_state.j) {
        const auto old_side = frame.side;
        czipperz::turn_left(frame.side);
        frame.player.turn(old_side, frame.side);
        std::printf("Side%d\t", frame.side);
    }
    if (key_state.l && !previous_key_state.l) {
        const auto old_side = frame.side;
        czipperz::turn_right(frame.side);
        frame.player.turn(old_side, frame.side);
        std::printf("Side%d\t", frame.side);
    }

    // Update objects
    if (frame.draw_menu) {
        frame.menu.update(key_state, previous_key_state);
    } else {
        frame.player.update(frame, key_state, previous_key_state);
    }
}

static void sleep(std::chrono::microseconds& start_time) {
    const std::chrono::microseconds current_time =
        czipperz::current_time();
    if (czipperz::calc_length + start_time > current_time) {
        std::this_thread::sleep_for(czipperz::calc_length +
                                    start_time - current_time);
    } else {
#ifndef NDEBUG
        std::puts("Skipped calc frame");
#endif
    }
    start_time += czipperz::calc_length;
}

void calculator_thread(sdl::renderer* rend) {
    sdl::renderer& renderer = *rend;
    czipperz::level
        level(sdl::img::load_texture(renderer,
                                     "res/level_1_background.png"),
              sdl::img::load_texture(renderer,
                                     "res/level_1_background.png"),
              sdl::img::load_texture(renderer,
                                     "res/level_1_background.png"),
              sdl::img::load_texture(renderer,
                                     "res/level_1_background.png"));
    level.platforms.push_back(
        czipperz::platform({0, 0}, {0, 0}, 100, 100, 50));
    level.platforms.push_back(
        czipperz::platform({200, 0}, {400, 0}, 250, 100, 50));
    level.platforms.push_back(
        czipperz::platform({350, 0}, {0, 0}, 400, 100, 50));
    level.platforms.push_back(
        czipperz::platform({500, 0}, {400, 0}, 550, 100, 50));

    czipperz::frame frames[2];
    frames[0].level = &level;
    frames[1].level = &level;
    czipperz::frame* frame = frames + 0;
    czipperz::frame* previous_frame = frames + 1;

    czipperz::key_state previous_key_state;

    std::chrono::microseconds start_time = czipperz::current_time();

    while (!czipperz::quit) {
        send_to_render(frame, previous_frame);

        czipperz::key_state key_state = previous_key_state;
        handle_key_events(key_state);

        calculate(*frame, key_state, previous_key_state);

        previous_key_state = key_state;

        sleep(start_time);
    }
}
}
