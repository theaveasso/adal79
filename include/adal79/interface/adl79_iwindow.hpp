#ifndef __ADAL79_INTERFACE_IWINDOW_H_
#define __ADAL79_INTERFACE_IWINDOW_H_

namespace adl
{

class iwindow
{
  virtual ~iwindow() = default;

  void poll_event();
};

} // namespace adl

#endif // __ADAL79_INTERFACE_IWINDOW_H_
