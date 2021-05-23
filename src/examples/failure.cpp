#include "examples/failure.hpp"

#include <exc_loc/failure>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_failure()
{
	try
	{
		throw exc_loc::ios_base::failure( "throw std::ios_base::failure" );
	}
	catch ( const exc_loc::ios_base::failure & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

