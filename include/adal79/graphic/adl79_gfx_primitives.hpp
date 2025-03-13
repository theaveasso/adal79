#ifndef __ADAL79_GRAPHIC_GFX_PRIMITIVES_H_
#define __ADAL79_GRAPHIC_GFX_PRIMITIVES_H_

#include <SDL3/SDL.h>

#include "adal79/adl79_define.hpp"
#include "adal79/math.h"

namespace adl {

/*
 */
void draw_circle_rgba(SDL_Renderer *p_renderer, const vec2f &p_pos, float p_rad,
                      const adl_color &p_color);



} // namespace adl

#endif // __ADAL79_GRAPHIC_GFX_PRIMITIVES_H_
