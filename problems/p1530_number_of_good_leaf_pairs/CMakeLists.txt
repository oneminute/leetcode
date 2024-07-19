cmake_minimum_required (VERSION 3.8)

project ("p1530_number_of_good_leaf_pairs")

add_executable(p1530_number_of_good_leaf_pairs "sol01.cpp")
target_link_libraries(p1530_number_of_good_leaf_pairs PRIVATE ${leetcode_link_libraries})

