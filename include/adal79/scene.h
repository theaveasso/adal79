// #ifndef ADAL79_SCENE_H
// #define ADAL79_SCENE_H
//
// #include <SDL3_ttf/SDL_ttf.h>
//
// #include "adal79/ecs/registry.h"
// #include "adal79/system/input.h"
//
// namespace adl {
// class scene {
// public:
//   virtual ~scene() = default;
//
//   virtual void on_create(entt::registry &r) = 0;
//   virtual void on_teardown(entt::registry &r) = 0;
//
//   virtual void on_enter(entt::registry &r) = 0;
//   virtual void on_exit(entt::registry &r) = 0;
//
//   virtual void on_update(entt::registry &r, float dt) = 0;
//   virtual void on_last_update(entt::registry &r, float dt) = 0;
//   virtual void on_render(entt::registry &r) = 0;
//   virtual void on_event(entt::registry &r) = 0;
// };
//
// class intro_scene final : public scene {
// public:
//   void on_create(entt::registry &r) override;
//   void on_teardown(entt::registry &r) override;
//
//   void on_enter(entt::registry &r) override;
//   void on_exit(entt::registry &r) override;
//
//   void on_update(entt::registry &r, float dt) override;
//   void on_last_update(entt::registry &r, float dt) override;
//   void on_render(entt::registry &r) override;
//   void on_event(entt::registry &r) override;
//
//   void set_switch_to_scene_id(unsigned int id);
//
// private:
//   unsigned int m_switch_to_scene_id;
//   float m_visible_duration{3};
//   float m_last_duration{};
// };
//
// class game_scene final : public scene {
// public:
//   void on_create(entt::registry &r) override;
//   void on_teardown(entt::registry &r) override;
//
//   void on_enter(entt::registry &r) override;
//   void on_exit(entt::registry &r) override;
//
//   void on_update(entt::registry &r, float dt) override;
//   void on_last_update(entt::registry &r, float dt) override;
//   void on_render(entt::registry &r) override;
//   void on_event(entt::registry &r) override;
//
// private:
//   input m_input;
// };
// } // namespace adl
//
// #endif // ADAL79_SCENE_H
