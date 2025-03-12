#ifndef ADAL79_H
#define ADAL79_H

#include <memory>
#include <variant>

using std::make_shared;
using std::shared_ptr;

using std::make_unique;
using std::unique_ptr;

constexpr int TARGET_FPS = 60;
constexpr double FRAME_TIME = 1.0 / 60.0;

template <typename T> using adl_result = std::variant<T, std::string>;

#endif // ADAL79_H
