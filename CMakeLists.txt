# CMakeList.txt : CMake project for leetcode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("leetcode")

include("cmake/macros.cmake")
add_subdirectory(SimpleTest)

set(leetcode_include_dirs
    SimpleTest    
)
include_directories(${leetcode_include_dirs})

set(leetcode_link_libraries
    SimpleTest
)

# Add source to this project's executable.
add_executable (leetcode "leetcode.cpp" "leetcode.h" )

add_subdirectory(questions)


# TODO: Add tests and install targets if needed.
