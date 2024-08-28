cmake_minimum_required (VERSION 3.8)

project ("bubblesort")

add_executable(bubblesort "sol01.cpp")
target_link_libraries(bubblesort PRIVATE ${leetcode_link_libraries})

