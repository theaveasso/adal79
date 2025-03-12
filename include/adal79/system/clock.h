#ifndef __ADAL79_SYSTEM_CLOCK_H_
#define __ADAL79_SYSTEM_CLOCK_H_

#include <chrono>

namespace adl {

using clock_impl = std::chrono::high_resolution_clock;

class clock {
public:
  [[nodiscard]] float get_elapsed_time() const;
  [[nodiscard]] bool is_running() const;

  void start();
  void stop();

  float restart();
  float reset();

private:
  clock_impl::time_point m_ref_point{clock_impl::now()};
  clock_impl::time_point m_stop_point;
};

} // namespace adl

#endif // __ADAL79_SYSTEM_CLOCK_H_
