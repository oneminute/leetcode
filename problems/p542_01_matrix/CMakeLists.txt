cmake_minimum_required (VERSION 3.8)

project ("p542_01_matrix")

add_executable(p542_01_matrix "sol01.cpp")
target_link_libraries(p542_01_matrix PRIVATE ${leetcode_link_libraries})

