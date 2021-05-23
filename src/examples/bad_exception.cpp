#include "examples/bad_exception.hpp"

#include <exc_loc/bad_exception>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_exception()
{
	try
	{
		throw exc_loc::bad_exception();
	}
	catch ( const exc_loc::bad_exception & exception )
	{
		std::cout
		<< "throw std::bad_exception"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

