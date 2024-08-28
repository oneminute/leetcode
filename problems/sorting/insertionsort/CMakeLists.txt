cmake_minimum_required (VERSION 3.8)

project ("insertionsort")

add_executable(insertionsort "sol01.cpp")
target_link_libraries(insertionsort PRIVATE ${leetcode_link_libraries})

