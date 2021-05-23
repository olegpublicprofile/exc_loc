#include "examples/bad_array_new_length.hpp"

#include <exc_loc/bad_array_new_length>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_array_new_length()
{
#ifdef EXCLOC_CPP11
	try
	{
		throw exc_loc::bad_array_new_length();
	}
	catch ( const exc_loc::bad_array_new_length & exception )
	{
		std::cout
		<< "throw std::bad_array_new_length"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
#endif
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

