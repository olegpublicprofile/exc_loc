#include "examples/logic_error.hpp"

#include <exc_loc/logic_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_logic_error()
{
	try
	{
		throw exc_loc::logic_error( "throw std::logic_error" );
	}
	catch ( const exc_loc::logic_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

