#ifndef __ADAL79_SYSTEM_ASSET_MANAGEMENT_SYSTEM_H_
#define __ADAL79_SYSTEM_ASSET_MANAGEMENT_SYSTEM_H_

#include <string>
#include <unordered_map>

#include <SDL3/SDL.h>

#include "adal79/adl79_define.hpp"
#include "adal79/graphic/adl79_asset.hpp"

namespace adl {

template <asset T>
class asset_manager {
public:
  virtual ~asset_manager() = default;

  virtual adl_result<std::shared_ptr<T>>
               load_asset(std::string_view p_filename)   = 0;
  virtual void unload_asset(std::string_view p_filename) = 0;

protected:
  std::unordered_map<std::string, shared_ptr<T>> m_assets;
};

} // namespace adl

#endif // __ADAL79_SYSTEM_ASSET_MANAGEMENT_SYSTEM_H_
