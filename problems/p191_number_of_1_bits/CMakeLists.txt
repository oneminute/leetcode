cmake_minimum_required (VERSION 3.8)

project ("p191_number_of_1_bits")

add_executable(p191_number_of_1_bits "sol01.cpp")
target_link_libraries(p191_number_of_1_bits PRIVATE ${leetcode_link_libraries})

