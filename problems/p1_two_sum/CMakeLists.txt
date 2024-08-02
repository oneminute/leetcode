cmake_minimum_required (VERSION 3.8)

project ("p1_two_sum")

add_executable(p1_two_sum "sol01.cpp")
target_link_libraries(p1_two_sum PRIVATE ${leetcode_link_libraries})

