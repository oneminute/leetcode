cmake_minimum_required (VERSION 3.8)

project ("knapsack_zero_one")

add_executable(knapsack_zero_one "sol01.cpp")
target_link_libraries(knapsack_zero_one PRIVATE ${leetcode_link_libraries})

