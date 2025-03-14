#include "adal79/ecs/adl79_component.hpp"

namespace adl {

c_id::c_id(std::string_view p_name, std::string_view p_group)
    : name(p_name), group(p_group) {}

void transform_component::set_position(const vec2f &p_pos) {
  t.matrix[12] = p_pos.x;
  t.matrix[13] = p_pos.y;
}

c_circle::c_circle() {};

c_circle::c_circle(float p_radius) : radius(p_radius) {}

} // namespace adl
