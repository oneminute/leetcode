cmake_minimum_required (VERSION 3.8)

project ("mergesort")

add_executable(mergesort "sol01.cpp")
target_link_libraries(mergesort PRIVATE ${leetcode_link_libraries})

