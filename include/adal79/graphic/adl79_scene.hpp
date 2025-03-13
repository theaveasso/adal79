#ifndef __ADAL79_GRAPHIC_SCENE_H_
#define __ADAL79_GRAPHIC_SCENE_H_

#include <concepts>

#include <SDL3/SDL.h>

namespace adl {

template <typename T>
concept scene = requires(T a, float p_dt) {
  { a.on_activate() } -> std::same_as<void>;
  { a.on_deactivate() } -> std::same_as<void>;

  { a.on_enter() } -> std::same_as<void>;
  { a.on_exit() } -> std::same_as<void>;

  { a.on_update(p_dt) } -> std::same_as<void>;
  { a.on_render() } -> std::same_as<void>;
  { a.on_process_event() } -> std::same_as<void>;
};

} // namespace adl

#endif // __ADAL79_GRAPHIC_TEXTURE_H_
