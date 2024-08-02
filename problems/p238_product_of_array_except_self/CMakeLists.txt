cmake_minimum_required (VERSION 3.8)

project ("p238_product_of_array_except_self")

add_executable(p238_product_of_array_except_self "sol01.cpp")
target_link_libraries(p238_product_of_array_except_self PRIVATE ${leetcode_link_libraries})

