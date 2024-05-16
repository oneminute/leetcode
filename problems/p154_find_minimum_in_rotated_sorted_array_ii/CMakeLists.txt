cmake_minimum_required (VERSION 3.8)

project ("p154_find_minimum_in_rotated_sorted_array_ii")

add_executable(p154_find_minimum_in_rotated_sorted_array_ii "sol01.cpp")
target_link_libraries(p154_find_minimum_in_rotated_sorted_array_ii PRIVATE ${leetcode_link_libraries})

