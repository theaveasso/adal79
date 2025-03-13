#ifndef __ADAL79_ADL79_DEFINE_H_
#define __ADAL79_ADL79_DEFINE_H_

#include <memory>
#include <variant>

#include <SDL3/SDL.h>

using std::make_shared;
using std::shared_ptr;

using std::make_unique;
using std::unique_ptr;

constexpr int    TARGET_FPS = 60;
constexpr double FRAME_TIME = 1.0 / 60.0;

template <typename T>
using adl_result = std::variant<T, std::string>;

using adl_color  = SDL_FColor;

constexpr adl_color adl_red{255, 0, 0, 255};
constexpr adl_color adl_green{0, 255, 0, 255};
constexpr adl_color adl_blue{0, 0, 255, 255};

constexpr int adl_KEY_COUNT = 256;

#endif // __ADAL79_ADL79_DEFINE_H_
