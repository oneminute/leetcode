cmake_minimum_required (VERSION 3.8)

project ("p435_non_overlapping_intervals")

add_executable(p435_non_overlapping_intervals "sol01.cpp")
target_link_libraries(p435_non_overlapping_intervals PRIVATE ${leetcode_link_libraries})

