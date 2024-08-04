cmake_minimum_required (VERSION 3.8)

project ("p338_count_bits")

add_executable(p338_count_bits "sol01.cpp")
target_link_libraries(p338_count_bits PRIVATE ${leetcode_link_libraries})

