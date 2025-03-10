// #ifndef ADAL79_SYSTEM_H
// #define ADAL79_SYSTEM_H
//
// #include <entt.hpp>
// #include <memory>
// #include <string_view>
// #include <unordered_map>
// #include <utility>
//
// #include <SDL3/SDL.h>
//
// namespace adl {
// class scene;
//
// class system {
// public:
//   explicit system(entt::registry &r);
//
//   entt::registry &get_registry() { return m_registry; }
//
// protected:
//   entt::registry &m_registry;
// };
//
// class s_asset final : public system {
// public:
//   explicit s_asset(entt::registry &r);
//
//   unsigned int texture_add(std::string_view path);
//   void texture_remove(unsigned int id);
//   SDL_Texture* texture_get(unsigned int id);
//
//   void load_texture_from_rendered_text(std::string_view text, SDL_Color color);
//
// private:
//   using texture_id_pair = std::pair<unsigned int, SDL_Texture*>;
//
//   unsigned int m_current_texture_id;
//   std::unordered_map<std::string_view, texture_id_pair> m_textures;
// };
//
// class s_component final : public system {
// public:
//   explicit s_component(entt::registry &r);
//
//   template <typename T, typename... Args>
//   T& add(entt::entity &e, Args &&...args) {
//     m_registry.emplace<T>(e, std::forward<Args>(args)...);
//     return m_registry.get<T>(e);
//   }
//
//   template <typename T> T &get(entt::entity &e) { return m_registry.get<T>(e); }
//
//   template <typename T> void remove(entt::entity &e) {
//     m_registry.remove<T>(e);
//   }
//
//   template <typename T, typename... Args>
//   T& replace(entt::registry &r, entt::entity &e, Args &&...args) {
//     m_registry.replace<T>(e, std::forward<Args>(args)...);
//     return m_registry.get<T>(e);
//   }
// };
//
// class s_scene final : public system {
// public:
//   explicit s_scene(entt::registry &r);
//
//   void update(float dt);
//   void render();
//   void process_event();
//
//   unsigned int add(std::shared_ptr<scene> s);
//   void remove(unsigned int id);
//   void switch_to(unsigned int id);
//
// private:
//   unsigned int m_total_scene_count{};
//
//   std::shared_ptr<scene> m_current_scene;
//   std::unordered_map<unsigned int, std::shared_ptr<scene>> m_scenes;
// };
// } // namespace adl
//
// #endif // ADAL79_SYSTEM_H
