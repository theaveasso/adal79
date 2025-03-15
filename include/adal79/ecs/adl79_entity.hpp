#ifndef ADAL79_ECS_ENTITY_H
#define ADAL79_ECS_ENTITY_H

namespace adl
{
class entity
{
  public:
    explicit entity(entt::registry& p_registry);

    template <typename T, typename... Args>
    void add_component(Args&&... args)
    {
        m_registry.emplace<T>(m_entity, std::forward<Args>(args)...);
    }

    template <typename T>
    T& get_component()
    {
        return m_registry.get<T>(m_entity);
    }

    template <typename T>
    void remove_component()
    {
        m_registry.remove<T>();
    }

    inline entt::entity& get() { return m_entity; }

  private:
    entt::registry& m_registry;
    entt::entity    m_entity;
};
} // namespace adl
#endif // ADAL79_ECS_ENTITY_H
