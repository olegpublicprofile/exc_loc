# Exception with location

Implementation for proposal add location to exceptions. In C++20 was added
*std::source_location* class and idea is add *source_location* method to
standard exceptions and add default parameter with value
*std::source_location::current()* in constructor:

```c++
namespace std {
  class exception {
  public:
    exception(
       const source_location & source_location = source_location::current()
    ) noexcept;
    ...
    const source_location & source_location() const noexcept;
    ...
  };
}
```

It will help to understand where the exception was thrown without debugger

## Table of Contents

* [Old Code](#old-code)
* [New Code](#new-code)
* [Examples](#examples)
* [Build examples](#build-examples)
* [Docker image](#docker-image)
* [Compilers that don't support std::source_location](#compilers-that-dont-support-stdsource_location)
* [Live example](#live-example)

## Old Code

```c++
#include <stdexcept>
#include <iostream>

void f1( int index ) {
    // ...
    if( index < 0 )
        throw std::logic_error{ "index < 0" };
    // ...
}

void f2( int index ) {
    // ...
    if( index < 0 )
        throw std::logic_error{ "index < 0" };
    // ...
}

int main() {
    try    {
        f1( -1 );
        f2( 0 );
    }
    catch( const std::logic_error & error )    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
```

Output:

```
index < 0
```

It's difficult to understand where exception was thrown

## New Code

If throw exception from this library result can be:

```c++
#include <exc_loc/logic_error>
#include <iostream>

void f1( int index ) {
    // ...
    if( index < 0 )
        throw exc_loc::logic_error{ "index < 0" };
    // ...
}

void f2( int index ) {
    // ...
    if( index < 0 )
        throw exc_loc::logic_error{ "index < 0" };
    // ...
}

int main() {
    try    {
        f1( -1 );
        f2( 0 );
    }
    catch( const exc_loc::logic_error & error )    {
        const std::source_location & location = error.source_location();
        std::cout << error.what() << " in " << location.file_name()
        << ":" << location.line()
        << " function: " << location.function_name()
        << std::endl;
    }
    return 0;
}
```

Output:

```
index < 0 in main.cpp:7 function: f1
```

Now it's easy understand that the exception was thrown in function *f1*
and in file *main.cpp* line *7* without debugger

## Examples

You can find more examples with other exceptions in:
[src/examples](src/examples)

## Build examples

```
mkdir build
cd build
cmake ..
cmake -build .
```

## Compilers that don't support std::source_location

This library has implementation of std::source_location for C++17. This
implementation use *__builtin_FILE()*, *__builtin_FUNCTION()* and
*__builtin_LINE()* functions.

See details: [include/exc_loc/source_location_cpp17.hpp](include/exc_loc/source_location_cpp17.hpp)

If you want use this implementation instead *#include \<source_locaion\>* or
*#include \<experimental/source_location\>* you can build examples with
option EXCLOC_IGNORE_SYSTEM_HEADERS:

```
mkdir -p build
cd build
cmake .. -DEXCLOC_IGNORE_SYSTEM_HEADERS=ON
cmake -build .
```

Tested:

* Windows: Visual Studio 2019
* Linux: GCC and Clang
* macOS: Apple Clang

## Docker image

You can test this implementation in docker image:

```sh
docker build -t exc_loc .
```

## Live example

* Url: [https://godbolt.org/z/YGnfGf3s9](https://godbolt.org/z/YGnfGf3s9)
* Code:

```c++
/* begin details.hpp */
//------------------------------------------------------------------------------

#ifdef __has_include
#    if __has_include(<version>)
#        include <version>
#    endif
#endif

#ifdef __cpp_lib_source_location
    #if EXCLOC_CPP_VERSION >= __cpp_lib_source_location
        #define EXCLOC_COMPILER_SUPPORT_LOCATION
    #endif
#endif

#ifndef EXCLOC_COMPILER_SUPPORT_LOCATION
    #ifdef __has_include
        #if __has_include(<experimental/source_location>)
            #define EXCLOC_COMPILER_SUPPORT_EXPERIMENTAL_LOCATION
        #endif
    #endif
#endif

//------------------------------------------------------------------------------
/* end details.hpp */

/* begin include_source_location.hpp */
//------------------------------------------------------------------------------

//#define EXCLOC_IGNORE_SYSTEM_HEADERS
#if defined(EXCLOC_COMPILER_SUPPORT_LOCATION) && !defined (EXCLOC_IGNORE_SYSTEM_HEADERS)
    #include <source_location>
#elif defined (EXCLOC_COMPILER_SUPPORT_EXPERIMENTAL_LOCATION) && !defined (EXCLOC_IGNORE_SYSTEM_HEADERS)
    #include <experimental/source_location>
namespace std {
    using std::experimental::source_location;
}
#else
/* begin source_location_cpp17.hpp */
//------------------------------------------------------------------------------
#include <cstdint>

namespace std {
struct source_location
{
    constexpr source_location() noexcept
        :    m_file_name{ "unknown" }
        ,    m_function_name{ m_file_name }
        ,    m_line{ 0 }
        ,    m_column{ 0 }
    {}

    static constexpr source_location current(
        const char * _file = __builtin_FILE(),
        const char * _func = __builtin_FUNCTION(),
        int _line = __builtin_LINE(),
        int _col = 0
    ) noexcept
    {
        source_location location;
        location.m_file_name = _file;
        location.m_function_name = _func;
        location.m_line = _line;
        location.m_column = _col;
        return location;
    }
    constexpr uint_least32_t line() const noexcept { return m_line;}
    constexpr uint_least32_t column() const noexcept{ return m_column; }
    constexpr const char * file_name() const noexcept{ return m_file_name;}
    constexpr const char * function_name() const noexcept{return m_function_name;}

private:
    const char * m_file_name;
    const char * m_function_name;
    uint_least32_t m_line;
    uint_least32_t m_column;
  };
/* end source_location_cpp17.hpp */
//------------------------------------------------------------------------------

}
#endif

/* begin exc_loc/exception */
//------------------------------------------------------------------------------
#include <exception>
#include <string>

namespace exc_loc {

class exception : public std::exception
{
public:

    exception(
        std::string _msg,
        const std::source_location & _loc = std::source_location::current()
    ) noexcept
        :    m_msg{ std::move( _msg ) }
        ,    m_source_location{ _loc }
    {}

    exception( std::source_location && _loc ) noexcept
        :    m_source_location{ std::move( _loc ) }
    {}

    const std::source_location & source_location() const noexcept { return m_source_location;}
    const char * what() const noexcept override { return m_msg.c_str();}

private:

    const std::string m_msg;
    const std::source_location m_source_location;
};

} // namespace exc_loc

/* end exc_loc/exception */
//------------------------------------------------------------------------------

/* begin examples/exception */
//------------------------------------------------------------------------------
#include <iostream>

namespace examples {
void run_example_exception()
{
    try
    {
        throw exc_loc::exception( "throw std::exception in" );
    }
    catch ( const exc_loc::exception & exception )
    {
        const std::source_location & loc = exception.source_location();
        std::cout
            << exception.what()
            << " in file:"
            << loc.file_name()
            << ":"
            << loc.line()
            << ":"
            << loc.column()
            << " function: "
            << loc.function_name()
            << std::endl
        ;
    }
}
} // namespace examples

/* end examples/exception */
//------------------------------------------------------------------------------

int main()
{
    examples::run_example_exception();

    return 0;
}

```
