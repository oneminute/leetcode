cmake_minimum_required (VERSION 3.8)

project ("p88_merge_sorted_array")

add_executable(p88_merge_sorted_array "sol01.cpp")
target_link_libraries(p88_merge_sorted_array PRIVATE ${leetcode_link_libraries})

