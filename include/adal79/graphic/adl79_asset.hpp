#ifndef __ADAL79_GRAPHIC_ASSET_H_
#define __ADAL79_GRAPHIC_ASSET_H_

namespace adl
{
template <typename T>
concept asset = requires(T a, std::string_view p_filename) {
	{ a.load(p_filename) } -> std::convertible_to<bool>;
	{ a.unload() } -> std::same_as<void>;
};
} // namespace adl

#endif // __ADAL79_GRAPHIC_ASSET_H_
