#include "examples/invalid_argument.hpp"

#include <exc_loc/invalid_argument>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_invalid_argument()
{
	try
	{
		throw exc_loc::invalid_argument( "throw std::invalid_argument" );
	}
	catch ( const exc_loc::invalid_argument & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

