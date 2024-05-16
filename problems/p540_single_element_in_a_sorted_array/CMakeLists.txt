cmake_minimum_required (VERSION 3.8)

project ("p540_single_element_in_a_sorted_array")

add_executable(p540_single_element_in_a_sorted_array "sol01.cpp")
target_link_libraries(p540_single_element_in_a_sorted_array PRIVATE ${leetcode_link_libraries})

