cmake_minimum_required (VERSION 3.8)

project ("p75_sort_colors")

add_executable(p75_sort_colors "sol01.cpp")
target_link_libraries(p75_sort_colors PRIVATE ${leetcode_link_libraries})

