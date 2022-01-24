# CMakeList.txt : CMake project for leetcode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("longest-substring-without-repeating-characters-sol1")

add_executable(longest-substring-without-repeating-characters-sol1 "sol01.cpp")
target_link_libraries(longest-substring-without-repeating-characters-sol1 PRIVATE ${leetcode_link_libraries})


# TODO: Add tests and install targets if needed.
