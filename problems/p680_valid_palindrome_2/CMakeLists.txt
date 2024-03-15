cmake_minimum_required (VERSION 3.8)

project ("p680_valid_palindrome_2")

add_executable(p680_valid_palindrome_2 "sol01.cpp")
target_link_libraries(p680_valid_palindrome_2 PRIVATE ${leetcode_link_libraries})

