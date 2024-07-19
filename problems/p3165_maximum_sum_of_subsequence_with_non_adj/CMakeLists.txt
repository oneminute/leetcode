cmake_minimum_required (VERSION 3.8)

project ("p3165_maximum_sum_of_subsequence_with_non_adj")

add_executable(p3165_maximum_sum_of_subsequence_with_non_adj "sol01.cpp")
target_link_libraries(p3165_maximum_sum_of_subsequence_with_non_adj PRIVATE ${leetcode_link_libraries})

