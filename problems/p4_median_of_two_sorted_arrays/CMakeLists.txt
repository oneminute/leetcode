cmake_minimum_required (VERSION 3.8)

project ("p4_median_of_two_sorted_arrays")

add_executable(p4_median_of_two_sorted_arrays "sol01.cpp")
target_link_libraries(p4_median_of_two_sorted_arrays PRIVATE ${leetcode_link_libraries})

