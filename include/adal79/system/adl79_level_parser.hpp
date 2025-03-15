#ifndef __ADAL79_SYSTEM_LEVEL_PARSER_HPP_
#define __ADAL79_SYSTEM_LEVEL_PARSER_HPP_

#include "adal79/ecs/adl79_registry.hpp"
#include "adal79/system/adl79_file_handler.hpp"

namespace adl
{
class level_parser
{
  public:
    explicit level_parser(registry& registry, shared_ptr<file_handler> handler);
    ~level_parser();

    void parse();

    inline void set_tile_size(int tile_size) { m_tile_size = tile_size; }

  private:
    registry&          m_registry;
    shared_ptr<file_handler> m_handler;

    int m_tile_size = 16;
};

} // namespace adl

#endif // __ADAL79_SYSTEM_LEVEL_PARSER_HPP_
