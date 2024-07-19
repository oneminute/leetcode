cmake_minimum_required (VERSION 3.8)

project ("p165_compare_version_numbers")

add_executable(p165_compare_version_numbers "sol01.cpp")
target_link_libraries(p165_compare_version_numbers PRIVATE ${leetcode_link_libraries})

