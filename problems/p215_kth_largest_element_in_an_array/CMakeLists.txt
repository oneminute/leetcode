cmake_minimum_required (VERSION 3.8)

project ("p215_kth_largest_element_in_an_array")

add_executable(p215_kth_largest_element_in_an_array "sol01.cpp")
target_link_libraries(p215_kth_largest_element_in_an_array PRIVATE ${leetcode_link_libraries})

