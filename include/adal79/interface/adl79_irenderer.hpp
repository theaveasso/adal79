#ifndef __ADAL79_INTERFACE_IRENDERER_H_
#define __ADAL79_INTERFACE_IRENDERER_H_

#include <SDL3/SDL.h>

#include "adal79/adl79_define.hpp"
#include "adal79/graphic/adl79_texture.hpp"
#include "adal79/math.h"

namespace adl
{
class irenderer
{
  public:
	virtual ~irenderer() = default;

	virtual SDL_Renderer& get() = 0;

	virtual void begin_frame() = 0;

	virtual void end_frame() = 0;

	virtual void draw_texture(shared_ptr<texture> t, int pos_x, int pos_y, adl_Color tint) = 0;

	virtual void draw_texture_v(shared_ptr<texture> texture, vec2i position, adl_Color tint) = 0;

	virtual void draw_texture_ex(shared_ptr<texture> texture, const SDL_FRect& src, vec2i position, adl_Color tint) = 0;

	virtual void draw_texture_rec(shared_ptr<texture> texture, const SDL_FRect& src, const SDL_FRect& dest,
								  vec2i origin, float rot, adl_Color tint) = 0;
};
} // namespace adl

#endif // __ADAL79_INTERFACE_IRENDERER_H_
