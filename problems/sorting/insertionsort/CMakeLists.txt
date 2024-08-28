cmake_minimum_required (VERSION 3.8)

project ("sorting-insertionsort")

add_executable(sorting-insertionsort "sol01.cpp")
target_link_libraries(sorting-insertionsort PRIVATE ${leetcode_link_libraries})

