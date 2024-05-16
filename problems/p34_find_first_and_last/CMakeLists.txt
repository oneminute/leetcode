cmake_minimum_required (VERSION 3.8)

project ("p34_find_first_and_last")

add_executable(p34_find_first_and_last "sol01.cpp")
target_link_libraries(p34_find_first_and_last PRIVATE ${leetcode_link_libraries})

