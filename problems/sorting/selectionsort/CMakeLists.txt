cmake_minimum_required (VERSION 3.8)

project ("selectionsort")

add_executable(selectionsort "sol01.cpp")
target_link_libraries(selectionsort PRIVATE ${leetcode_link_libraries})

