cmake_minimum_required (VERSION 3.8)

project ("24-points")

add_executable("24-points" "sol01.cpp")
target_link_libraries("24-points" PRIVATE ${leetcode_link_libraries})
