#include "adal79/graphics/gfx_primitives.h"

namespace adl {

void draw_circle_rgba(SDL_Renderer *p_renderer, const vec2f &p_pos, float p_rad,
                      const adl_color &p_color) {
  const int num_segments = 32;

  SDL_Vertex *vertices   = new SDL_Vertex[num_segments + 2];

  vertices[0].position.x = p_pos.x;
  vertices[0].position.y = p_pos.y;
  vertices[0].color      = p_color;

  for (int i = 0; i <= num_segments; i++) {
    float angle                = 2.0f * M_PI * i / num_segments;
    vertices[i + 1].position.x = p_pos.x + p_rad * cosf(angle);
    vertices[i + 1].position.y = p_pos.y + p_rad * sinf(angle);
    vertices[i + 1].color      = p_color;
  }

  int *indices = new int[num_segments * 3];
  for (int i = 0; i < num_segments; i++) {
    indices[i * 3]     = 0;
    indices[i * 3 + 1] = i + 1;
    indices[i * 3 + 2] = i + 2 > num_segments ? 1 : i + 2;
  }

  SDL_RenderGeometry(p_renderer, nullptr, vertices, num_segments + 2, indices,
                     num_segments * 3);

  delete[] vertices;
  delete[] indices;
}

} // namespace adl
