#include "adal79/core/adl79_mem_tracker.hpp"
#include <iostream>

namespace adl
{
size_t memory_tracker::s_allocations = 0;
size_t memory_tracker::s_deallocations = 0;

void memory_tracker::reset()
{
	s_allocations = 0;
	s_deallocations = 0;
}

void memory_tracker::report_allocation()
{
	s_allocations++;
}

void memory_tracker::report_deallocation()
{
	s_deallocations++;
}

bool memory_tracker::is_balanced()
{
	return s_allocations == s_deallocations;
}

void memory_tracker::show_status()
{
	std::cout << "memory stats - allocations: " << s_allocations << " , deallocations: " << s_deallocations
			  << " , balanced: " << (is_balanced() ? "yes" : "no") << std::endl;
}

} // namespace adl
