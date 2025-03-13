#ifndef __ADAL79_ECS_COMPONENT_H_
#define __ADAL79_ECS_COMPONENT_H_

#include <string>

#include <entt.hpp>

#include "adal79/adl79_define.hpp"
#include "adal79/graphic/adl79_texture.hpp"
#include "adal79/graphic/adl79_transform.hpp"

namespace adl {

struct c_id {
  std::string name  = "default";
  std::string group = "default";

  c_id()            = default;
  c_id(std::string_view p_name, std::string_view p_group);
};

struct c_velocity {
  vec2f vel    = {1.0, 1.0};

  c_velocity() = default;
};

struct c_transform {
  transform t;

  void         set_position(const vec2f &p_pos);
  inline vec2f get_position() { return {t.matrix[12], t.matrix[13]}; }
};

struct c_sprite {
  SDL_FRect           src{};
  SDL_FRect           dest{};
  shared_ptr<texture> tex;

  c_sprite(shared_ptr<texture> p_texture);
  c_sprite(shared_ptr<texture> p_texture, const SDL_FRect &p_src,
           const SDL_FRect &p_dest);

  template <typename T>
  c_sprite &set(T c_sprite::*member, const T &value) {
    this->*member = value;
    return *this;
  }

  c_sprite &set_tex(shared_ptr<texture> p_tex);
};

struct c_circle {
  float     radius{10};
  adl_color color{adl_red};

  c_circle();
  c_circle(float p_radius);

  template <typename T>
  c_circle &set(T c_circle::*member, T value) {
    this->*member = value;
    return *this;
  }
};

} // namespace adl

#endif // __ADAL79_ECS_COMPONENT_H_
