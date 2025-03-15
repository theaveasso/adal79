#ifndef __ADAL79_INTERFACE_ADL79_IRENDERER_HPP_
#define __ADAL79_INTERFACE_ADL79_IRENDERER_HPP_

#include "adal79/graphic/adl79_texture.hpp"

namespace adl
{
class irenderer
{
  public:
    virtual ~irenderer() = default;

    virtual SDL_Renderer& get() = 0;

    virtual void begin_frame() = 0;
    virtual void end_frame()   = 0;

    // Basic shapes drawing functions
    // Draw a color-filled rectangle
    virtual void draw_rectangle_rec(rect rectangle, color color) = 0;
    // Draw rectangle outline with extended parameters
    virtual void draw_rectangle_lines_ex(rect rectangle, float line_thick, color color) = 0;

    // Texture drawing functions
    // Draw a Texture2D
    virtual void draw_texture(const shared_ptr<texture>& texture, int posX, int posY, color tint) = 0;
    // Draw a Texture2D with position defined as Vector2
    virtual void draw_texture_v(const shared_ptr<texture>& texture, vec2 position, color tint) = 0;
    // Draw a Texture2D with extended parameters
    virtual void draw_texture_ex(const shared_ptr<texture>& texture, vec2 position, float rotation, float scale, color tint) = 0;
    // Draw a part of a texture defined by a rectangle
    virtual void draw_texture_rec(const shared_ptr<texture>& texture, rect source, vec2 position, color tint) = 0;
    // Draw a part of a texture defined by a rectangle with 'pro' parameters
    virtual void draw_texture_pro(const shared_ptr<texture>& texture, rect source, rect dest, vec2 origin, float rotation, color tint) = 0;
};
} // namespace adl

#endif // __ADAL79_INTERFACE_ADL79_IRENDERER_HPP_
