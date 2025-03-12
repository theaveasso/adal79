#include "adal79/ecs/component.h"

namespace adl {

c_sprite::c_sprite(shared_ptr<texture> p_texture)
    : tex(p_texture), dest(), src() {}

c_sprite::c_sprite(shared_ptr<texture> p_texture, const SDL_FRect &p_src,
                   const SDL_FRect &p_dest)
    : tex(p_texture), src(p_src), dest(p_dest) {}

c_sprite &c_sprite::set_tex(shared_ptr<texture> p_tex) {
  this->tex = p_tex;
  return *this;
}

} // namespace adl
