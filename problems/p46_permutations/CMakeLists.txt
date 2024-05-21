cmake_minimum_required (VERSION 3.8)

project ("p46_permutations")

add_executable(p46_permutations "sol01.cpp")
target_link_libraries(p46_permutations PRIVATE ${leetcode_link_libraries})

