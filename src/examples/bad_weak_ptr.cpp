#include "examples/bad_weak_ptr.hpp"

#include <exc_loc/bad_weak_ptr>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_weak_ptr()
{
	try
	{
		throw exc_loc::bad_weak_ptr();
	}
	catch ( const exc_loc::bad_weak_ptr & exception )
	{
		std::cout
		<< "throw std::bad_weak_ptr"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

