cmake_minimum_required (VERSION 3.8)

project ("p1636_sort_array_by_increasing_frequency")

add_executable(p1636_sort_array_by_increasing_frequency "sol01.cpp")
target_link_libraries(p1636_sort_array_by_increasing_frequency PRIVATE ${leetcode_link_libraries})

