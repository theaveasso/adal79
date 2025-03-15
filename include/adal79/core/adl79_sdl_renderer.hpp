#ifndef __ADAL79_CORE_SDL_RENDERER_HPP_
#define __ADAL79_CORE_SDL_RENDERER_HPP_

#include "adal79/interface/adl79_irenderer.hpp"

namespace adl
{

class sdl_renderer final : public irenderer
{
  public:
    explicit sdl_renderer(SDL_Window& p_window);
    ~sdl_renderer() override;

    void begin_frame() override;
    void end_frame() override;

    void draw_rectangle_rec(rect rectangle, color color) override;
    void draw_rectangle_lines_ex(rect rectangle, float line_thick, color color) override;

    void draw_texture(const shared_ptr<texture>& texture, int posX, int posY, color tint) override;
    void draw_texture_v(const shared_ptr<texture>& texture, vec2 position, color tint) override;
    void draw_texture_ex(const shared_ptr<texture>& texture, vec2 position, float rotation, float scale, color tint) override;
    void draw_texture_rec(const shared_ptr<texture>& texture, rect source, vec2 position, color tint) override;
    void draw_texture_pro(const shared_ptr<texture>& texture, rect source, rect dest, vec2 origin, float rotation, color tint) override;

    inline SDL_Renderer& get() override { return *m_renderer; }

  private:
    SDL_Window& m_window;

    unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;

  private:
    bool init();
};

} // namespace adl

#endif // __ADAL79_GRAPHICS_RENDERER_H_
