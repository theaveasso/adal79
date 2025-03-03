#ifndef ADAL79_MATH_H
#define ADAL79_MATH_H

namespace adl {
template <typename T> struct vec2 {
  T x{}, y{};

  constexpr vec2() = default;
  constexpr vec2(T px, T py) : x(px), y(py) {}

  [[nodiscard]] constexpr vec2 operator-() { return vec2(-x, -y); }

  [[nodiscard]] constexpr vec2 operator-(const vec2 &rhs) {
    return vec2(x - rhs.x, y - rhs.y);
  }

  constexpr vec2 &operator-=(vec2<T> &rhs) {
    this->x - rhs.x;
    this->y - rhs.y;
    return *this;
  }

  [[nodiscard]] constexpr vec2 operator+() { return vec2(x, y); }

  [[nodiscard]] constexpr vec2 operator+(const vec2 &rhs) {
    return vec2(x + rhs.x, y + rhs.y);
  }

  constexpr vec2 &operator+=(vec2<T> &rhs) {
    this->x + rhs.x;
    this->y + rhs.y;
    return *this;
  }
};

using vec2i = vec2<int>;
using vec2f = vec2<float>;
using vec2u = vec2<unsigned int>;
} // namespace math

#endif // ADAL79_MATH_H
