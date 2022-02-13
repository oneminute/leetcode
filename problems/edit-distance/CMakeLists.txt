cmake_minimum_required (VERSION 3.8)

project ("edit-distance")

add_executable("edit-distance" "sol01.cpp")
target_link_libraries("edit-distance" PRIVATE ${leetcode_link_libraries})
