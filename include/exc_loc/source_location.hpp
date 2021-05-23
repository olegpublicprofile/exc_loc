#pragma once

#include "internal_details.hpp"

#if defined(EXCLOC_COMPILER_SUPPORT_LOCATION) && !defined (EXCLOC_IGNORE_SYSTEM_HEADERS)
	#include <source_location>
#elif defined (EXCLOC_COMPILER_SUPPORT_EXPERIMENTAL_LOCATION) && !defined (EXCLOC_IGNORE_SYSTEM_HEADERS)
	#include <experimental/source_location>
namespace std {
	using std::experimental::source_location;
}
#else
	#include "source_location_cpp17.hpp"
#endif
