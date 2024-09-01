cmake_minimum_required (VERSION 3.8)

project ("p221_maximal_square")

add_executable(p221_maximal_square "sol01.cpp")
target_link_libraries(p221_maximal_square PRIVATE ${leetcode_link_libraries})

