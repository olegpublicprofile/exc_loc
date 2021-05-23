#pragma once

//------------------------------------------------------------------------------

#ifdef __has_include
#	if __has_include(<version>)
#		include <version>
#	endif
#endif

//------------------------------------------------------------------------------

#if defined(_MSVC_LANG)
#	define EXCLOC_CPP_VERSION _MSVC_LANG
#elif defined(__cplusplus)
#	define EXCLOC_CPP_VERSION __cplusplus
#endif

//------------------------------------------------------------------------------

#ifdef __cpp_lib_source_location
	#if EXCLOC_CPP_VERSION >= __cpp_lib_source_location
		#define EXCLOC_COMPILER_SUPPORT_LOCATION
	#endif
#endif

//------------------------------------------------------------------------------

#ifndef EXCLOC_COMPILER_SUPPORT_LOCATION
	#ifdef __has_include
		#if __has_include(<experimental/source_location>)
			#define EXCLOC_COMPILER_SUPPORT_EXPERIMENTAL_LOCATION
		#endif
	#endif
#endif

//------------------------------------------------------------------------------

#if EXCLOC_CPP_VERSION >= 201103L
	#define EXCLOC_CPP11  201103L
#endif

#if EXCLOC_CPP_VERSION >= 201402L
	#define EXCLOC_CPP14  201402L
#endif

#if EXCLOC_CPP_VERSION >= 201703L
	#define EXCLOC_CPP17  201703L
#endif

#if EXCLOC_CPP_VERSION >= 202002L
	#define EXCLOC_CPP20  202002L
#endif

//------------------------------------------------------------------------------

#if (EXCLOC_CPP_VERSION >= EXCLOC_CPP11)
	#define EXCLOC_NOEXCEPT noexcept
#else
	#define EXCLOC_NOEXCEPT throw()
#endif

