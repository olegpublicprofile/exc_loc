#include "examples/system_error.hpp"

#include <exc_loc/system_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_system_error()
{
#ifdef EXCLOC_CPP11
	try
	{
		throw exc_loc::system_error( std::error_code{}, "throw std::system_error" );
	}
	catch ( const exc_loc::system_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
#endif
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

