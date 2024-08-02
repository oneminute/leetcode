cmake_minimum_required (VERSION 3.8)

project ("p33_search_in_rotated_sorted_array")

add_executable(p33_search_in_rotated_sorted_array "sol01.cpp")
target_link_libraries(p33_search_in_rotated_sorted_array PRIVATE ${leetcode_link_libraries})

