#ifndef ADAL79_GRAPHIC_TRANSFORM_H
#define ADAL79_GRAPHIC_TRANSFORM_H

#include <array>

#include <SDL3/SDL.h>

#include "adal79/math.h"

namespace adl {

struct transform {
  std::array<float, 16> matrix{};

  constexpr transform() = default;

  constexpr transform(float p00, float p01, float p02, float p10, float p11,
                      float p12, float p20, float p21, float p22);

  // return the inverse of the transform.
  constexpr transform inverse() const;

  // tranform a rectangle
  constexpr vec2f tranform_rect(const SDL_FRect &p_rect) const;

  // tranform a point
  constexpr vec2f tranform_point(vec2f p_point) const;

  // combine the current transform with a translation.
  constexpr transform &translate(const vec2f &p_offset) {
    matrix[12] += p_offset.x;
    matrix[13] += p_offset.y;
    return *this;
  };

  // combine the current transform with a rotation.
  transform &rotate(angle p_angle);

  // combine the current transform with a rotation.
  transform &rotate(angle p_angle, vec2f p_center);

  // combine the current transform with a scaling.
  constexpr transform &scale(vec2f p_factors);

  // combine the current transform with a scaling.
  constexpr transform &scale(vec2f p_factors, vec2f p_center);
};

} // namespace adl

#endif // ADAL79_GRAPHIC_TRANSFORM_H
