#ifndef __ADAL79_GRAPHIC_TEXTURE_H_
#define __ADAL79_GRAPHIC_TEXTURE_H_

#include <string_view>

#include <SDL3/SDL.h>
#include <entt.hpp>

namespace adl {

class texture {
public:
  texture(SDL_Renderer& p_renderer);
  ~texture();

  bool load(std::string_view p_filepath);
  void unload();

  inline SDL_Texture* get() { return m_texture; }

private:
  SDL_Texture *m_texture;
  SDL_Renderer& m_renderer;
};

} // namespace adl

#endif // __ADAL79_GRAPHICS_TEXTURE_H_
