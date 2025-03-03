#ifndef ADAL79_SYSTEM_H
#define ADAL79_SYSTEM_H

#include <entt.hpp>
#include <memory>
#include <unordered_map>
#include <utility>

class scene;

class system {
public:
  virtual void run(entt::registry &r) = 0;
  virtual void run(float dt) = 0;
};

class s_component final : public system {
public:
  void run(entt::registry &r) override {};
  void run(float dt) override {};

  template <typename T, typename... Args>
  void add(entt::registry &r, entt::entity &e, Args &&...args) {
    r.emplace<T>(e, std::forward(args)...);
  }

  template <typename T> T &get(entt::registry &r, entt::entity &e) {
    return r.get<T>(e);
  }

  template <typename T> void remove(entt::registry &r, entt::entity &e) {
    r.remove<T>(e);
  }

  template <typename T, typename... Args>
  void replace(entt::registry &r, entt::entity &e, Args &&...args) {
    r.replace<T>(e, std::forward(args)...);
  }
};

class s_scene final : public system {
public:
  s_scene();
  void run(entt::registry &r) override {};
  void run(float dt) override;

  unsigned int add(std::shared_ptr<scene> s);
  void remove(unsigned int id);
  void switch_to(unsigned int id);

private:
  unsigned int m_total_scene_count{};

  std::shared_ptr<scene> m_current_scene;
  std::unordered_map<unsigned int, std::shared_ptr<scene>> m_scenes;
};

#endif // ADAL79_SYSTEM_H
