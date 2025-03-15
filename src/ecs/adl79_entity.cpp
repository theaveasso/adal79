#include "adal79/ecs/adl79_entity.hpp"

namespace adl
{
entity::entity(entt::registry& p_registry)
	: m_registry(p_registry)
{
	m_entity = m_registry.create();
}

} // namespace adl
