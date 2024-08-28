cmake_minimum_required (VERSION 3.8)

project ("sorting-bubblesort")

add_executable(sorting-bubblesort "sol01.cpp")
target_link_libraries(sorting-bubblesort PRIVATE ${leetcode_link_libraries})

