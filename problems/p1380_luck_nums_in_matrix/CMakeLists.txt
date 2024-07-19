cmake_minimum_required (VERSION 3.8)

project ("p1380_luck_nums_in_matrix")

add_executable(p1380_luck_nums_in_matrix "sol01.cpp")
target_link_libraries(p1380_luck_nums_in_matrix PRIVATE ${leetcode_link_libraries})

