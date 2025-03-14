#ifndef __ADAL79_ECS_COMPONENT_H_
#define __ADAL79_ECS_COMPONENT_H_

#include <string>

#include <entt.hpp>

#include "adal79/adl79_define.hpp"
#include "adal79/graphic/adl79_texture.hpp"
#include "adal79/graphic/adl79_transform.hpp"

namespace adl
{

struct c_id
{
  std::string name  = "default";
  std::string group = "default";

  c_id() = default;
  c_id(std::string_view p_name, std::string_view p_group);
};

struct c_velocity
{
  vec2f vel = {1.0, 1.0};

  c_velocity() = default;
};

struct transform_component
{
  transform t;

  void         set_position(const vec2f &p_pos);
  inline vec2f get_position() { return {t.matrix[12], t.matrix[13]}; }
};

struct sprite_component
{
  SDL_FRect           src{};
  SDL_FRect           dest{};
  shared_ptr<texture> tex;

  sprite_component() {}
};

struct c_circle
{
  float     radius{10};
  adl_Color color{adl_Red};

  c_circle();
  c_circle(float p_radius);

};

struct animation_component
{
  int   current_frame  = 0;
  int   frame_count    = 0;
  int   frames_per_row = 1;
  float frame_rate     = 24.0f;
  float time_elapsed   = 0.0f;
  bool  playing        = true;
  bool  loop           = true;

  animation_component() {}
};

} // namespace adl

#endif // __ADAL79_ECS_COMPONENT_H_
