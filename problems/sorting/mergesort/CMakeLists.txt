cmake_minimum_required (VERSION 3.8)

project ("sorting-mergesort")

add_executable(sorting-mergesort "sol01.cpp")
target_link_libraries(sorting-mergesort PRIVATE ${leetcode_link_libraries})

