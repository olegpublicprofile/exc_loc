#include "examples/future_error.hpp"

#include <exc_loc/future_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_future_error()
{
	try
	{
		throw exc_loc::future_error( std::future_errc::no_state );
	}
	catch ( const exc_loc::future_error & exception )
	{
		std::cout
		<< "throw std::future_error"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

