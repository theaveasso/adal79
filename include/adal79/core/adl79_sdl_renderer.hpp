#ifndef __ADAL79_CORE_RENDERER_H_
#define __ADAL79_CORE_RENDERER_H_

#include <SDL3/SDL.h>
#include <entt.hpp>

#include "adal79/adl79_define.hpp"
#include "adal79/interface/adl79_irenderer.hpp"
#include "adal79/math.h"

namespace adl
{

class sdl_renderer final : public irenderer
{
  public:
	explicit sdl_renderer( SDL_Window& p_window );
	~sdl_renderer() override;

	void begin_frame() override;
	void end_frame() override;

	void draw_texture( shared_ptr<texture> texture, int pos_x, int pos_y, adl_Color tint ) override;

	void draw_texture_v( shared_ptr<texture> texture, vec2i position, adl_Color tint ) override;

	void draw_texture_ex( shared_ptr<texture> texture, const SDL_FRect& source, vec2i position,
						  adl_Color tint ) override;

	void draw_texture_rec( shared_ptr<texture> texture, const SDL_FRect& source, const SDL_FRect& dest, vec2i origin,
						   float rotation, adl_Color tint ) override;

	inline SDL_Renderer& get() override { return *m_renderer; }

  private:
	SDL_Window& m_window;

	unique_ptr<SDL_Renderer, decltype( &SDL_DestroyRenderer )> m_renderer;

  private:
	bool init();
};

} // namespace adl

#endif // __ADAL79_GRAPHICS_RENDERER_H_
