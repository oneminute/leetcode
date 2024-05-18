cmake_minimum_required (VERSION 3.8)

project ("p451_sort_characters_by_frequency")

add_executable(p451_sort_characters_by_frequency "sol01.cpp")
target_link_libraries(p451_sort_characters_by_frequency PRIVATE ${leetcode_link_libraries})

