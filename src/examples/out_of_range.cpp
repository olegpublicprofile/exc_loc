#include "examples/out_of_range.hpp"

#include <exc_loc/out_of_range>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_out_of_range()
{
	try
	{
		throw exc_loc::out_of_range( "throw std::out_of_range" );
	}
	catch ( const exc_loc::out_of_range & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

