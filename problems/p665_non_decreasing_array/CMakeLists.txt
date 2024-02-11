cmake_minimum_required (VERSION 3.8)

project ("p665_non_decreasing_array")

add_executable(p665_non_decreasing_array "sol01.cpp")
target_link_libraries(p665_non_decreasing_array PRIVATE ${leetcode_link_libraries})

