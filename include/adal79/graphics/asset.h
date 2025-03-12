#ifndef __ADAL79_GRAPHICS_ASSET_H_
#define __ADAL79_GRAPHICS_ASSET_H_

#include <concepts>
#include <string_view>

#include <SDL3/SDL.h>
#include <entt.hpp>

namespace adl {

template <typename T>
concept asset =
    requires(T a, std::string_view p_filename) {
      { a.load(p_filename) } -> std::convertible_to<bool>;
      { a.unload() } -> std::same_as<void>;
    };

} // namespace adl

#endif // __ADAL79_GRAPHICS_ASSET_H_
