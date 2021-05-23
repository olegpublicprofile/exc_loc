#include "examples/runtime_error.hpp"

#include <exc_loc/runtime_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_runtime_error()
{
	try
	{
		throw exc_loc::runtime_error( "throw std::runtime_error" );
	}
	catch ( const exc_loc::runtime_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

