#include "examples/bad_function_call.hpp"

#include <exc_loc/bad_function_call>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_bad_function_call()
{
	try
	{
		throw exc_loc::bad_function_call();
	}
	catch ( const exc_loc::bad_function_call & exception )
	{
		std::cout
		<< "throw std::bad_function_call"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

