cmake_minimum_required (VERSION 3.8)

project ("longest-common-subsequence")

add_executable("longest-common-subsequence" "sol01.cpp")
target_link_libraries("longest-common-subsequence" PRIVATE ${leetcode_link_libraries})
