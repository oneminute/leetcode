cmake_minimum_required (VERSION 3.8)

project ("sorting-quicksort")

add_executable(sorting-quicksort "sol01.cpp")
target_link_libraries(sorting-quicksort PRIVATE ${leetcode_link_libraries})

