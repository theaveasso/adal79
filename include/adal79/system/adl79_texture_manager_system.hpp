#ifndef __ADAL79_SYSTEM_TEXTURE_MANAGER_SYSTEM_H_
#define __ADAL79_SYSTEM_TEXTURE_MANAGER_SYSTEM_H_

#include "adal79/graphic/adl79_texture.hpp"
#include "adal79/interface/adl79_irenderer.hpp"
#include "adal79/system/adl79_asset_manager.hpp"

namespace adl
{

class texture_manager final : public asset_manager<texture>
{
  public:
	texture_manager(irenderer& renderer);

	result<shared_ptr<texture>> load_asset(std::string_view p_filename) override;
	void unload_asset(std::string_view p_filename) override;

	shared_ptr<texture> create(std::string_view p_filename);

  private:
	irenderer& m_renderer;
};

} // namespace adl

#endif
