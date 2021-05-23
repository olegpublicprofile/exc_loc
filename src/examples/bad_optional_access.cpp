#include "examples/bad_optional_access.hpp"

#include <exc_loc/bad_optional_access>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_optional_access()
{
#ifdef EXCLOC_CPP17

	try
	{
		throw exc_loc::bad_optional_access();
	}
	catch ( const exc_loc::bad_optional_access & exception )
	{
		std::cout
		<< "throw std::bad_optional_access"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}

#endif
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

