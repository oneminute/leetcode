cmake_minimum_required (VERSION 3.8)

project ("p153_find_minimum_in_rotated_sorted_array")

add_executable(p153_find_minimum_in_rotated_sorted_array "sol01.cpp")
target_link_libraries(p153_find_minimum_in_rotated_sorted_array PRIVATE ${leetcode_link_libraries})

