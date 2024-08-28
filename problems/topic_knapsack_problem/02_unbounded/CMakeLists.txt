cmake_minimum_required (VERSION 3.8)

project ("knapsack_unbounded")

add_executable(knapsack_unbounded "sol01.cpp")
target_link_libraries(knapsack_unbounded PRIVATE ${leetcode_link_libraries})

