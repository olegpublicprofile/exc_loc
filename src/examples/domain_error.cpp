#include "examples/domain_error.hpp"

#include <exc_loc/domain_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_domain_error()
{
	try
	{
		throw exc_loc::domain_error( "throw std::domain_error" );
	}
	catch ( const exc_loc::domain_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

