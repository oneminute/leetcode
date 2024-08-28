cmake_minimum_required (VERSION 3.8)

project ("sorting-selectionsort")

add_executable(sorting-selectionsort "sol01.cpp")
target_link_libraries(sorting-selectionsort PRIVATE ${leetcode_link_libraries})

