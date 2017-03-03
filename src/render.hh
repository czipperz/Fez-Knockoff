#ifndef HEADER_GUARD_RENDER_H
#define HEADER_GUARD_RENDER_H

#include "sdl/renderer.hh"
#include "sdl/texture.hh"

namespace czipperz {
class frame;
void render(sdl::renderer&, sdl::texture&, const czipperz::frame&);
}

#endif
