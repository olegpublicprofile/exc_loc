cmake_minimum_required(VERSION 3.5)

project(exception_with_location LANGUAGES CXX)

option(EXCLOC_IGNORE_SYSTEM_HEADERS
	"Include implementaition std::source_location from this library"
)

if(EXCLOC_IGNORE_SYSTEM_HEADERS)
   add_definitions(-DEXCLOC_IGNORE_SYSTEM_HEADERS)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories( "./src/" "include/" )

file(GLOB all_sources "./src/*.cpp" "./src/*/*.cpp")
add_executable(${PROJECT_NAME} ${all_sources})
