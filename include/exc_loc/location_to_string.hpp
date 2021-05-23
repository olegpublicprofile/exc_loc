#pragma once

#include "source_location.hpp"

#include <string>

//------------------------------------------------------------------------------

namespace exc_loc {

//------------------------------------------------------------------------------

static std::string to_string(
	const std::string & _whatMsg,
	const std::source_location & _loc
)
{
	return
		_whatMsg
		+ " in "
		+ _loc.file_name()
		+ ":"
		+ std::to_string( _loc.line() )
		+ ":"
		+ std::to_string( _loc.column() )
		+ " function: "
		+ _loc.function_name()
	;
}

//------------------------------------------------------------------------------

}
