#ifndef ADAL79_SCENE_H
#define ADAL79_SCENE_H

#include "registry.h"

class scene {
public:
  explicit scene(entt::registry &r);

  virtual ~scene() = default;

  virtual void on_create() = 0;
  virtual void on_teardown() = 0;

  virtual void on_enter() = 0;
  virtual void on_exit() = 0;

  virtual void on_update(float dt) = 0;
  virtual void on_last_update(float dt) = 0;
  virtual void on_render() = 0;
  virtual void on_event() = 0;

  entt::registry &get_registry() { return m_registry; }

protected:
  entt::registry &m_registry;
};

class intro_scene final : public scene {
public:
  explicit intro_scene(entt::registry &r);

  void on_create() override;
  void on_teardown() override;

  void on_enter() override;
  void on_exit() override;

  void on_update(float dt) override;
  void on_last_update(float dt) override;
  void on_render() override;
  void on_event() override;

  void set_switch_to_scene_id(unsigned int id);

private:
  unsigned int m_switch_to_scene_id;
  float m_visible_duration{3};
  float m_last_duration{};
};

class game_scene final : public scene {
public:
  explicit game_scene(entt::registry &r);

  void on_create() override;
  void on_teardown() override;

  void on_enter() override;
  void on_exit() override;

  void on_update(float dt) override;
  void on_last_update(float dt) override;
  void on_render() override;
  void on_event() override;
};

#endif // ADAL79_SCENE_H
