cmake_minimum_required (VERSION 3.8)

project ("choir")

add_executable(choir "sol01.cpp")
target_link_libraries(choir PRIVATE ${leetcode_link_libraries})

