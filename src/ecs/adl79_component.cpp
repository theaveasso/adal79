#include "adal79/ecs/adl79_component.hpp"

namespace adl {

c_id::c_id(std::string_view p_name, std::string_view p_group)
    : name(p_name), group(p_group) {}

void c_transform::set_position(const vec2f &p_pos) {
  t.matrix[12] = p_pos.x;
  t.matrix[13] = p_pos.y;
}

c_sprite::c_sprite(shared_ptr<texture> p_texture)
    : tex(p_texture), dest(), src() {}

c_sprite::c_sprite(shared_ptr<texture> p_texture, const SDL_FRect &p_src,
                   const SDL_FRect &p_dest)
    : tex(p_texture), src(p_src), dest(p_dest) {}

c_sprite &c_sprite::set_tex(shared_ptr<texture> p_tex) {
  this->tex = p_tex;
  return *this;
}

c_circle::c_circle() {};

c_circle::c_circle(float p_radius) : radius(p_radius) {}

} // namespace adl
