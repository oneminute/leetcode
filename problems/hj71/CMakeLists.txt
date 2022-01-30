cmake_minimum_required (VERSION 3.8)

project ("hj71")

add_executable("hj71" "sol01.cpp")
target_link_libraries("hj71" PRIVATE ${leetcode_link_libraries})
