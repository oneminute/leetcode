cmake_minimum_required (VERSION 3.8)

project ("p371_sum_of_two_integers")

add_executable(p371_sum_of_two_integers "sol01.cpp")
target_link_libraries(p371_sum_of_two_integers PRIVATE ${leetcode_link_libraries})

