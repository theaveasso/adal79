#ifndef __ADAL79_ADL79_DEFINE_H_
#define __ADAL79_ADL79_DEFINE_H_

#include <iostream>
#include <memory>
#include <variant>

#include <SDL3/SDL.h>

using std::make_shared;
using std::shared_ptr;

using std::make_unique;
using std::unique_ptr;

constexpr int TARGET_FPS = 60;
constexpr double FRAME_TIME = 1.0 / 60.0;

template <typename T>
using result = std::variant<T, std::string>;

using color = SDL_FColor;
using rect = SDL_FRect;

constexpr color adl_White{255, 255, 255, 255};
constexpr color adl_Red{255, 0, 0, 255};
constexpr color adl_Green{0, 255, 0, 255};
constexpr color adl_Blue{0, 0, 255, 255};

constexpr int adl_KEY_COUNT = 256;

#ifdef adl_Debug
#define adl_debug_constructor(service) std::cout << "[~] " << #service << " create" << std::endl;
#define adl_debug_deconstructor(service) std::cout << "[~] " << #service << " destroy" << std::endl;
#else
#define adl_debug_deconstructor(service)
#define adl_debug_constructor(service)
#endif // DEBUG

#endif // __ADAL79_ADL79_DEFINE_H_
