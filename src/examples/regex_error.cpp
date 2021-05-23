#include "examples/regex_error.hpp"

#include <exc_loc/regex_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_regex_error()
{
#ifdef EXCLOC_CPP11
	try
	{
		throw exc_loc::regex_error( std::regex_constants::error_collate );
	}
	catch ( const exc_loc::regex_error & exception )
	{
		std::cout
		<< "throw std::regex_error"
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
#endif
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------
