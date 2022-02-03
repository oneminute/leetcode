cmake_minimum_required (VERSION 3.8)

project ("wildcard-matching")

add_executable("wildcard-matching" "sol01.cpp")
target_link_libraries("wildcard-matching" PRIVATE ${leetcode_link_libraries})
