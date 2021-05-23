#include "examples/underflow_error.hpp"

#include <exc_loc/underflow_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_underflow_error()
{
	try
	{
		throw exc_loc::underflow_error( "throw std::underflow_error" );
	}
	catch ( const exc_loc::underflow_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

