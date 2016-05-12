#cmake_minimum_required(version 3.2)

project(testGame)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(ALL_EXECUTEABLE_BIN_COMPILE_FLAGS "-Wall -pedantic -g")
#set(ALL_LIBRARY_BIN_COMPILE_FLAGS "-Wall -pedantic -g")
set(CMAKE_CXX_FLAGS "-Wall -pedantic -g -std=c++11 -pthread")

add_subdirectory(base)

add_subdirectory(engine)

add_subdirectory(testgame)

add_subdirectory(etest)
