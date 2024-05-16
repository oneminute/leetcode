cmake_minimum_required (VERSION 3.8)

project ("p340_longest_k_unique_characters_substring")

add_executable(p340_longest_k_unique_characters_substring "sol01.cpp")
target_link_libraries(p340_longest_k_unique_characters_substring PRIVATE ${leetcode_link_libraries})

