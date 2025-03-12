#include <cassert>
#include <string>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "adal79/graphics/texture.h"

namespace adl {

texture::texture(SDL_Renderer &p_renderer) : m_renderer(p_renderer) {}
texture::~texture() { unload(); }

bool texture::load(std::string_view p_filename) {
  auto surf = IMG_Load(std::string(p_filename).c_str());
  if (!surf) {
    SDL_LogError(SDL_LOG_CATEGORY_RENDER,
                 "failed to load image from path: %s: %s",
                 std::string(p_filename).c_str(), SDL_GetError());
  }

  m_texture = SDL_CreateTextureFromSurface(&m_renderer, surf);
  if (!m_texture) {
    SDL_LogError(SDL_LOG_CATEGORY_RENDER,
                 "failed to create texture from surface: %s: %s",
                 std::string(p_filename).c_str(), SDL_GetError());
  }

  SDL_DestroySurface(surf);

  return true;
}

void texture::unload() {
  if (!m_texture) {
    SDL_DestroyTexture(m_texture);
    m_texture = nullptr;
  }
}

} // namespace adl
