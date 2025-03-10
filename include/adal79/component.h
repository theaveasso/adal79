#ifndef ADAL79_COMPONENT_H
#define ADAL79_COMPONENT_H

#include <SDL3/SDL.h>

namespace adl {

// struct c_texture {
//   unsigned int texture_id;
//   int width, height;
//
//   c_texture(unsigned int pid) : texture_id(pid) {};
// };
//
// struct c_motion {
//   vec2f acceleration;
//   vec2f velocity;
//
//   c_motion() = default;
//
//   inline void update(float dt) { velocity += acceleration * dt; };
// };
//
// struct c_transform {
//   transform t;
//
//   inline void update(float dt) {}
// };
//
// // c_transform specifies translate, rotate, scale, shear, project
// struct c_sprite {
//   SDL_FRect dest, res;
//   SDL_Texture *texture;
//
//   c_sprite() = default;
//
//   void draw(SDL_Renderer *renderer);
// };
//
// struct c_player_input {
//   float a = 0;
//   c_player_input() {};
// };
} // namespace adl

#endif // ADAL79_COMPONENT_H
