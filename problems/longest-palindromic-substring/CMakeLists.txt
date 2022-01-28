cmake_minimum_required (VERSION 3.8)

project ("longest-palindromic-substring-sol1")

add_executable(longest-palindromic-substring-sol1 "sol01.cpp")
target_link_libraries(longest-palindromic-substring-sol1 PRIVATE ${leetcode_link_libraries})

