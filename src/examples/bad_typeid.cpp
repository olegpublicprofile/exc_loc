#include "examples/bad_typeid.hpp"

#include <exc_loc/bad_typeid>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_typeid()
{
	try
	{
		throw exc_loc::bad_typeid();
	}
	catch ( const exc_loc::bad_typeid & exception )
	{
		std::cout
		<< "throw std::bad_typeid"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

