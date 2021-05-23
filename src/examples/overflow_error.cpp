#include "examples/overflow_error.hpp"

#include <exc_loc/overflow_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_overflow_error()
{
	try
	{
		throw exc_loc::overflow_error( "throw std::overflow_error" );
	}
	catch ( const exc_loc::overflow_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

