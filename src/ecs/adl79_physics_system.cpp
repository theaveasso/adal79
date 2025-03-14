#include "adal79/ecs/adl79_physics_system.hpp"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

namespace adl
{

physics_system::physics_system(entt::registry& registry)
	: m_registry(registry) {
		adl_debug_constructor(physics_system)
	};

physics_system::~physics_system() {};

void update(float dt)
{
};

} // namespace adl
