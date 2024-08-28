cmake_minimum_required (VERSION 3.8)

project ("quicksort")

add_executable(quicksort "sol01.cpp")
target_link_libraries(quicksort PRIVATE ${leetcode_link_libraries})

