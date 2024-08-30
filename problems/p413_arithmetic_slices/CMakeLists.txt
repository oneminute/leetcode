cmake_minimum_required (VERSION 3.8)

project ("p413_arithmetic_slices")

add_executable(p413_arithmetic_slices "sol01.cpp")
target_link_libraries(p413_arithmetic_slices PRIVATE ${leetcode_link_libraries})

