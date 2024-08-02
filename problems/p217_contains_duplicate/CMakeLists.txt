cmake_minimum_required (VERSION 3.8)

project ("p217_contains_duplicate")

add_executable(p217_contains_duplicate "sol01.cpp")
target_link_libraries(p217_contains_duplicate PRIVATE ${leetcode_link_libraries})

