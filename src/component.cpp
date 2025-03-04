#include "adal79/component.h"
#include <iostream>

namespace adl {
void c_sprite::draw(SDL_Renderer *renderer) {
  std::cout << "dest" << dest.w << " " << dest.h << "\n";
  SDL_RenderTexture(renderer, texture, nullptr, &dest);
}
} // namespace adl
