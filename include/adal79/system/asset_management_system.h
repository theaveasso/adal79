#ifndef __ADAL79_SYSTEM_ASSET_MANAGEMENT_SYSTEM_H_
#define __ADAL79_SYSTEM_ASSET_MANAGEMENT_SYSTEM_H_

#include <string>
#include <unordered_map>

#include <SDL3/SDL.h>

#include "adal79/adal79.h"
#include "adal79/graphics/asset.h"
#include "adal79/graphics/texture.h"

namespace adl {

template <asset T> class asset_manager {
public:
  virtual ~asset_manager() = default;

  virtual adl_result<std::shared_ptr<T>> load_asset(std::string_view p_filename) = 0;
  virtual void unload_asset(std::string_view p_filename) = 0;

protected:
  std::unordered_map<std::string, shared_ptr<T>> m_assets;
};

class texture_manager final : public asset_manager<texture> {
public:
  texture_manager(SDL_Renderer &p_renderer);

  adl_result<shared_ptr<texture>> load_asset(std::string_view p_filename) override;
  void unload_asset(std::string_view p_filename) override;

  shared_ptr<texture> create(std::string_view p_filename);
private:
  SDL_Renderer &m_renderer;
};

} // namespace adl

#endif // __ADAL79_SYSTEM_ASSET_MANAGEMENT_SYSTEM_H_
