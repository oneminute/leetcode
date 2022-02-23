cmake_minimum_required (VERSION 3.8)

project ("count-of-char")

add_executable(count-of-char "sol01.cpp")
target_link_libraries(count-of-char PRIVATE ${leetcode_link_libraries})

