#ifndef __ADAL79_ECS_ANIMATION_SYSTEM_H_
#define __ADAL79_ECS_ANIMATION_SYSTEM_H_

#include <entt.hpp>

namespace adl {
class animation_system {
public:
  explicit animation_system(entt::registry &p_registry);
  ~animation_system();

  void update(float dt);

private:
  entt::registry &m_registry;
};

} // namespace adl

#endif // __ADAL79_ECS_ANIMATION_SYSTEM_H_
