#ifndef ADAL79_ECS_COMPONENT_H
#define ADAL79_ECS_COMPONENT_H

#include <entt.hpp>
#include <string>

#include "adal79/adal79.h"
#include "adal79/graphics/texture.h"
#include "adal79/graphics/transform.h"

namespace adl {

struct c_id {
  std::string name = "default";
  std::string group = "default";
};

struct c_transform {
  transform t;
};

struct c_sprite {
  SDL_FRect src{};
  SDL_FRect dest{};
  shared_ptr<texture> tex;

  c_sprite(shared_ptr<texture> p_texture);
  c_sprite(shared_ptr<texture> p_texture, const SDL_FRect &p_src,
           const SDL_FRect &p_dest);

  template<typename T>
  c_sprite& set(T c_sprite::*member, const T& value) {
    this->*member = value;
    return *this;
  }

  c_sprite &set_tex(shared_ptr<texture> p_tex);
};

} // namespace adl
#endif // ADAL79_ECS_COMPONENT_H
