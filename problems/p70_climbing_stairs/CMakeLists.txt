cmake_minimum_required (VERSION 3.8)

project ("p70_climbing_stairs")

add_executable(p70_climbing_stairs "sol01.cpp")
target_link_libraries(p70_climbing_stairs PRIVATE ${leetcode_link_libraries})

