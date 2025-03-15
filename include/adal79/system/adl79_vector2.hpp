#ifndef __ADAL79_SYSTEM_VECTOR2_H_
#define __ADAL79_SYSTEM_VECTOR2_H_

namespace adl
{

struct vec2
{
    float x = 0, y = 0;

    constexpr vec2() = default;
    constexpr vec2(float v)
        : vec2(v, v)
    {
    }
    constexpr vec2(float x, float y)
        : x(x)
        , y(y)
    {
    }
};
} // namespace adl

#endif // __ADAL79_SYSTEM_VECTOR2_H_
