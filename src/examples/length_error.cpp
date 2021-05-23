#include "examples/length_error.hpp"

#include <exc_loc/length_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_length_error()
{
	try
	{
		throw exc_loc::length_error( "throw std::length_error" );
	}
	catch ( const exc_loc::length_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

