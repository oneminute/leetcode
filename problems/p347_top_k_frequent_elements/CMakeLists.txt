cmake_minimum_required (VERSION 3.8)

project ("p347_top_k_frequent_elements")

add_executable(p347_top_k_frequent_elements "sol01.cpp")
target_link_libraries(p347_top_k_frequent_elements PRIVATE ${leetcode_link_libraries})

