#ifndef __ADAL79_SYSTEM_ASSET_MANAGER_SYSTEM_HPP_
#define __ADAL79_SYSTEM_ASSET_MANAGER_SYSTEM_HPP_

#include "adal79/graphic/adl79_asset.hpp"

namespace adl
{

template <asset T>
class asset_manager
{
  public:
	virtual ~asset_manager() = default;

	virtual result<std::shared_ptr<T>> load_asset(std::string_view p_filename) = 0;
	virtual void unload_asset(std::string_view p_filename) = 0;

  protected:
	std::unordered_map<std::string, shared_ptr<T>> m_assets;
};

} // namespace adl

#endif // __ADAL79_SYSTEM_ASSET_MANAGER_SYSTEM_HPP_
