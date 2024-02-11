cmake_minimum_required (VERSION 3.8)

project ("p167_two_sum_ii")

add_executable(p167_two_sum_ii "sol01.cpp")
target_link_libraries(p167_two_sum_ii PRIVATE ${leetcode_link_libraries})

