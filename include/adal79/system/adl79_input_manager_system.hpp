#ifndef __ADAL79_SYSTEM_INPUT_MANAGER_SYSTEM_H_
#define __ADAL79_SYSTEM_INPUT_MANAGER_SYSTEM_H_

#include "adal79/adl79_define.hpp"
#include "adal79/window/adl79_keyboard.hpp"
namespace adl {
class input_manager {
public:
  input_manager(const input_manager&) = delete;
  input_manager& operator=(const input_manager&) = delete;
  input_manager(input_manager&&) = delete;
  input_manager& operator=(input_manager&&) = delete;

  static input_manager &get();
  inline keyboard& get_keyboard() { return *m_keyboard; }

private:
  input_manager();
  ~input_manager();

private:
  static input_manager* m_instance;

  unique_ptr<keyboard> m_keyboard;
};
} // namespace adl

#endif // __ADAL79_SYSTEM_INPUT_MANAGER_SYSTEM_H_
