#include "render.hh"
#include "frame.hh"

namespace czipperz {
static void render_platform(sdl::renderer& renderer, int side,
                            const czipperz::platform& platform) {
    renderer.set_draw_color(255, 0, 0);
    renderer.fill_rect(platform.get_side(side));
}

static void
render_level(sdl::renderer& renderer, const czipperz::level& level,
             czipperz::side side) {
    renderer.copy(level.textures[side]);
    for (const czipperz::platform& platform : level.platforms) {
        render_platform(renderer, side, platform);
    }
}

static void render_player(sdl::renderer& renderer,
                          const czipperz::player& player) {
    // Head
    renderer.set_draw_color(154, 155, 130);
    renderer.fill_rect(sdl::rect_of(player.x, player.y, 100, 100));

    // Mouth
    renderer.set_draw_color(0, 0, 0);
    renderer.fill_rect(
        sdl::rect_of(player.x + 20, player.y + 65, 60, 15));

    // Eyes direction
    int x_offset = 0;
    int y_offset = 0;
    if (player.dir[0]) {
        y_offset -= 5;
    }
    if (player.dir[1]) {
        y_offset += 5;
    }
    if (player.dir[2]) {
        x_offset -= 5;
    }
    if (player.dir[3]) {
        x_offset += 5;
    }

    // Eyes
    renderer.set_draw_color(255, 255, 255);
    renderer.fill_rect(sdl::rect_of(player.x + 20 + x_offset,
                                    player.y + 20 + y_offset, 20,
                                    20));
    renderer.fill_rect(sdl::rect_of(player.x + 60 + x_offset,
                                    player.y + 20 + y_offset, 20,
                                    20));

    // Pupil
    renderer.set_draw_color(0, 0, 0);
    renderer.fill_rect(sdl::rect_of(player.x + 27 + 2 * x_offset,
                                    player.y + 27 + 2 * y_offset, 6,
                                    6));
    renderer.fill_rect(sdl::rect_of(player.x + 67 + 2 * x_offset,
                                    player.y + 27 + 2 * y_offset, 6,
                                    6));
}

static void
render_menu(sdl::renderer& renderer, const czipperz::menu& menu) {
    renderer.set_draw_color(0, 0, 0, 100);
    renderer.fill();

    // FEZ word
    renderer.set_draw_color(255, 255, 255);
    renderer.fill_rect(sdl::rect_of(100, 90, 400, 120));

    if (menu.index == 0) {
        renderer.set_draw_color(100, 255, 100);
    } else {
        renderer.set_draw_color(100, 100, 100);
    }

    // F
    renderer.fill_rect(sdl::rect_of(120, 110, 20, 80));
    renderer.fill_rect(sdl::rect_of(120, 110, 60, 20));
    renderer.fill_rect(sdl::rect_of(120, 145, 50, 20));
    // E
    renderer.fill_rect(sdl::rect_of(200, 110, 20, 80));
    renderer.fill_rect(sdl::rect_of(200, 110, 60, 20));
    renderer.fill_rect(sdl::rect_of(200, 145, 60, 20));
    renderer.fill_rect(sdl::rect_of(200, 170, 60, 20));
    // Z
    renderer.fill_rect(sdl::rect_of(280, 110, 60, 20));
    renderer.fill_rect(sdl::rect_of(280, 170, 60, 20));
}

void render(sdl::renderer& renderer, sdl::texture& texture,
            const czipperz::frame& frame) {
    renderer.set_target(texture);

    renderer.set_draw_blend_mode(SDL_BLENDMODE_BLEND);

    render_level(renderer, *frame.level, frame.side);
    render_player(renderer, frame.player);
    if (frame.draw_menu) {
        render_menu(renderer, frame.menu);
    }

    renderer.unset_target();
    renderer.copy(texture);

    renderer.present();
}
}
