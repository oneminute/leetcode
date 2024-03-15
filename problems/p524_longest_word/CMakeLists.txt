cmake_minimum_required (VERSION 3.8)

project ("p524_longest_word")

add_executable(p524_longest_word "sol01.cpp")
target_link_libraries(p524_longest_word PRIVATE ${leetcode_link_libraries})

