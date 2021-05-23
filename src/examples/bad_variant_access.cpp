#include "examples/bad_variant_access.hpp"

#include <exc_loc/bad_variant_access>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_variant_access()
{
#ifdef EXCLOC_CPP17

	try
	{
		throw exc_loc::bad_variant_access();
	}
	catch ( const exc_loc::bad_variant_access & exception )
	{
		std::cout
		<< "throw std::bad_variant_access"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}

#endif
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

