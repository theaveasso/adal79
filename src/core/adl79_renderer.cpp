// #include <cassert>
//
// #include "adal79/core/adl79_renderer.hpp"
// #include "adal79/ecs/adl79_component.hpp"
// #include "adal79/graphic/adl79_gfx_primitives.hpp"
//
// namespace adl {
//
// renderer::renderer(SDL_Window &window, entt::registry &p_registry)
//     : m_registry(p_registry), m_window(window),
//       m_renderer(nullptr, SDL_DestroyRenderer) {
//   if (!init()) {
//     SDL_LogError(1, "failed to initialize engine renderer: %s", SDL_GetError());
//
//     return;
//   }
// }
//
// bool renderer::init() {
//   m_renderer.reset(SDL_CreateRenderer(&m_window, 0));
//   assert(m_renderer && "failed to create SDL_Renderer");
//   if (!m_renderer) {
//     SDL_Log("failed to create SDL_Renderer: %s", SDL_GetError());
//     return false;
//   }
//
//   SDL_SetRenderVSync(m_renderer.get(), SDL_RENDERER_VSYNC_ADAPTIVE);
//
//   return true;
// }
//
// void renderer::draw() {
//   clear();
//
//   auto view = m_registry.view<c_id, c_transform, c_circle>();
//   for (auto &entity : view) {
//     auto &transform = view.get<c_transform>(entity);
//     auto &circle    = view.get<c_circle>(entity);
//
//     draw_circle_rgba(m_renderer.get(), transform.get_position(), circle.radius,
//                      circle.color);
//   }
//
//   preset();
// }
//
// } // namespace adl
