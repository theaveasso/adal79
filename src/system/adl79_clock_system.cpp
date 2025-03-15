#include "adal79/system/adl79_clock.hpp"

namespace adl {

float clock::get_elapsed_time() const {
  using namespace std::chrono;
  if (is_running()) {
    return duration<float>(clock_impl::now() - m_ref_point).count();
  };
  return duration<float>(m_stop_point - m_ref_point).count();
}

bool clock::is_running() const {
  return m_stop_point == clock_impl::time_point();
}

void clock::start() {
  if (!is_running()) {
    m_ref_point += clock_impl::now() - m_stop_point;
    m_stop_point = {};
  }
}

void clock::stop() {
  if (is_running()) {
    m_stop_point = clock_impl::now();
  }
}

float clock::restart() {
  const float elapsed = get_elapsed_time();
  m_ref_point = clock_impl::now();
  m_stop_point = {};

  return elapsed;
}

float clock::reset() {
  const auto elapsed = get_elapsed_time();
  m_ref_point = clock_impl::now();
  m_stop_point = m_ref_point;
  return elapsed;
}

} // namespace adl
