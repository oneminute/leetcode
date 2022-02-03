cmake_minimum_required (VERSION 3.8)

project ("the-maze")

add_executable("the-maze" "sol01.cpp")
target_link_libraries("the-maze" PRIVATE ${leetcode_link_libraries})
