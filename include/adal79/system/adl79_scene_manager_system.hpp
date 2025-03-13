#ifndef __ADAL79_SYSTEM_SCENE_MANAGER_SYSTEM_H_
#define __ADAL79_SYSTEM_SCENE_MANAGER_SYSTEM_H_

#include <SDL3/SDL.h>
#include <entt.hpp>

namespace adl {

class scene_manager {
public:
  explicit scene_manager(entt::registry& p_registry);
  ~scene_manager();

  void switch_to(uint8_t scene_id);

  void on_activate();
  void on_deactivate();

  void on_enter();
  void on_exit();

  void on_update(float dt);
  void on_render();

  void on_process_event();


private:
  entt::registry &m_registry;
};

} // namespace adl

#endif
