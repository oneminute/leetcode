cmake_minimum_required (VERSION 3.8)

project ("length-of-last-string")

add_executable(length-of-last-string "sol01.cpp")
target_link_libraries(length-of-last-string PRIVATE ${leetcode_link_libraries})

