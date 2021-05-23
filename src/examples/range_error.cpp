#include "examples/range_error.hpp"

#include <exc_loc/range_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_range_error()
{
	try
	{
		throw exc_loc::range_error( "throw std::range_error" );
	}
	catch ( const exc_loc::range_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

