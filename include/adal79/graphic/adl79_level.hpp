#ifndef __ADAL79_GRAPHIC_SCENE_H_
#define __ADAL79_GRAPHIC_SCENE_H_

#include <concepts>

#include <SDL3/SDL.h>

namespace adl {

template <typename T>
concept level = requires(T a, float p_dt, SDL_Event &p_event) {
  { a.update(p_dt) } -> std::same_as<void>;
  { a.draw() } -> std::same_as<void>;
  { a.process_event(p_event) } -> std::same_as<void>;
};

} // namespace adl

#endif // __ADAL79_GRAPHIC_TEXTURE_H_
