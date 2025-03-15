#ifndef __ADAL79_C0RE_MEM_TRACKER_H_
#define __ADAL79_C0RE_MEM_TRACKER_H_

#include <cstddef>
namespace adl
{

class memory_tracker
{
  public:
	static void reset();

	static void report_allocation();
	static void report_deallocation();

	static bool is_balanced();

	static void show_status();

  private:
	static size_t s_allocations;
	static size_t s_deallocations;
};

} // namespace adl

#endif // __ADAL79_C0RE_MEM_TRACKER_H_
