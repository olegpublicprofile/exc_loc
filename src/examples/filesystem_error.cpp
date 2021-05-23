#include "examples/filesystem_error.hpp"

#include <exc_loc/filesystem_error>
#include <exc_loc/location_to_string.hpp>

#include <iostream>

//------------------------------------------------------------------------------

namespace examples {

//------------------------------------------------------------------------------

void run_example_filesystem_error()
{
#ifdef EXCLOC_CPP17
	try
	{
		throw exc_loc::filesystem::filesystem_error(
			"throw std::filesystem::filesystem_error",
			std::error_code{}
		);
	}
	catch ( const exc_loc::filesystem::filesystem_error & exception )
	{
		std::cout
		<< exc_loc::to_string( exception.what(), exception.source_location() )
		<< std::endl;
	}
#endif
}

//------------------------------------------------------------------------------

}

//------------------------------------------------------------------------------

