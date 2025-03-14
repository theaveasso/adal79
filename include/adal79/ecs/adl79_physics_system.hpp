#ifndef __ADAL79_ECS_PHYSICS_SYSTEM_H_
#define __ADAL79_ECS_PHYSICS_SYSTEM_H_

#include "adal79/ecs/adl79_registry.hpp"
namespace adl
{
class physics_system
{
  public:
	explicit physics_system(entt::registry& registry);
	~physics_system();

	void update(float dt);

  private:
	entt::registry& m_registry;
};
} // namespace adl

#endif // __ADAL79_ECS_PHYSICS_SYSTEM_H_
