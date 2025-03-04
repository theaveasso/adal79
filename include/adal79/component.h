#ifndef ADAL79_COMPONENT_H
#define ADAL79_COMPONENT_H

#include <SDL3/SDL.h>
#include <array>

#include "math.h"

namespace adl {
struct c_texture {
  unsigned int texture_id;
  int width, height;

  c_texture(unsigned int pid) : texture_id(pid) {};
};

// c_transform specifies translate, rotate, scale, shear, project
struct c_transform {
  vec2f positon;
  std::array<float, 16> matrix{};

  constexpr c_transform() = default;

  constexpr c_transform(float p00, float p01, float p02, float p10, float p11,
                        float p12, float p20, float p21, float p22);

  // return the inverse of the transform.
  constexpr c_transform inverse() const;

  // tranform a rectangle
  constexpr vec2f tranform_rect(const SDL_FRect &p_rect) const;

  // tranform a point
  constexpr vec2f tranform_point(vec2f p_point) const;

  // combine the current transform with a translation.
  constexpr c_transform &translate(vec2f p_offset);

  // combine the current transform with a rotation.
  c_transform &rotate(angle p_angle);

  // combine the current transform with a rotation.
  c_transform &rotate(angle p_angle, vec2f p_center);

  // combine the current transform with a scaling.
  constexpr c_transform &scale(vec2f p_factors);

  // combine the current transform with a scaling.
  constexpr c_transform &scale(vec2f p_factors, vec2f p_center);
};

struct c_sprite final {
  SDL_FRect dest, res;
  SDL_Texture* texture;

  c_sprite() = default;
  void draw(SDL_Renderer *renderer);
};
} // namespace adl

#endif // ADAL79_COMPONENT_H
