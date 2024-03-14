cmake_minimum_required (VERSION 3.8)

project ("p633_sum_of_square_numbers")

add_executable(p633_sum_of_square_numbers "sol01.cpp")
target_link_libraries(p633_sum_of_square_numbers PRIVATE ${leetcode_link_libraries})

