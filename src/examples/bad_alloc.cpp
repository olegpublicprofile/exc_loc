#include "examples/bad_alloc.hpp"

#include <exc_loc/bad_alloc>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_alloc()
{
	try
	{
		throw exc_loc::bad_alloc();
	}
	catch ( const exc_loc::bad_alloc & exception )
	{
		std::cout
		<< "throw std::bad_alloc"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

