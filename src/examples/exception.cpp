#include "examples/exception.hpp"

#include <exc_loc/exception>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_exception()
{
	try
	{
		throw exc_loc::exception( "throw std::exception" );
	}
	catch ( const exc_loc::exception & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

