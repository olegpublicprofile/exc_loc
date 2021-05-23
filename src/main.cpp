#include "examples/exception.hpp"

#include "examples/logic_error.hpp"
#include "examples/domain_error.hpp"
#include "examples/invalid_argument.hpp"
#include "examples/length_error.hpp"
#include "examples/out_of_range.hpp"
#include "examples/future_error.hpp"

#include "examples/bad_optional_access.hpp"

#include "examples/runtime_error.hpp"
#include "examples/range_error.hpp"
#include "examples/overflow_error.hpp"
#include "examples/underflow_error.hpp"
#include "examples/regex_error.hpp"
#include "examples/system_error.hpp"
#include "examples/failure.hpp"
#include "examples/filesystem_error.hpp"

#include "examples/bad_typeid.hpp"
#include "examples/bad_any_cast.hpp"
#include "examples/bad_weak_ptr.hpp"
#include "examples/bad_function_call.hpp"
#include "examples/bad_alloc.hpp"
#include "examples/bad_array_new_length.hpp"
#include "examples/bad_exception.hpp"
#include "examples/bad_variant_access.hpp"

#include <iostream>

//------------------------------------------------------------------------------

int main()
{
	auto printSeperator = [&](){ std::cout << std::endl; };

	examples::run_example_exception();

	printSeperator();

		examples::run_example_logic_error();
			examples::run_example_domain_error();
			examples::run_example_invalid_argument();
			examples::run_example_length_error();
			examples::run_example_out_of_range();
			examples::run_example_future_error();

	printSeperator();

		examples::run_example_bad_optional_access();

	printSeperator();

		examples::run_example_runtime_error();
			examples::run_example_range_error();
			examples::run_example_overflow_error();
			examples::run_example_underflow_error();
			examples::run_example_regex_error();
			examples::run_example_system_error();
				examples::run_example_failure();
				examples::run_example_filesystem_error();

	printSeperator();

	examples::run_example_bad_typeid();
	examples::run_example_bad_any_cast();
	examples::run_example_bad_weak_ptr();
	examples::run_example_bad_function_call();
	examples::run_example_bad_alloc();
		examples::run_example_bad_array_new_length();
	examples::run_example_bad_exception();
	examples::run_example_bad_variant_access();

	return 0;
}

