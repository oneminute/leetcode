cmake_minimum_required (VERSION 3.8)

project ("p152_maximum_product_subarray")

add_executable(p152_maximum_product_subarray "sol01.cpp")
target_link_libraries(p152_maximum_product_subarray PRIVATE ${leetcode_link_libraries})

