#include "examples/bad_any_cast.hpp"

#include <exc_loc/bad_any_cast>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_any_cast()
{
#ifdef EXCLOC_CPP17

	try
	{
		throw exc_loc::bad_any_cast();
	}
	catch ( const exc_loc::bad_any_cast & exception )
	{
		std::cout
		<< "throw std::bad_any_cast"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}

#endif
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------
