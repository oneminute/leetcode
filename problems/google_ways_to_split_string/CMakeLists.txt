cmake_minimum_required (VERSION 3.8)

project ("google_ways_to_split_string")

add_executable(google_ways_to_split_string "sol01.cpp")
target_link_libraries(google_ways_to_split_string PRIVATE ${leetcode_link_libraries})

