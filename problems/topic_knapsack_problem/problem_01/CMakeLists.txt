cmake_minimum_required (VERSION 3.8)

project ("knapsack_problem_01")

add_executable(knapsack_problem_01 "sol01.cpp")
target_link_libraries(knapsack_problem_01 PRIVATE ${leetcode_link_libraries})

