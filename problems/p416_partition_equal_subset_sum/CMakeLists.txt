cmake_minimum_required (VERSION 3.8)

project ("p416_partition_equal_subset_sum")

add_executable(p416_partition_equal_subset_sum "sol01.cpp")
target_link_libraries(p416_partition_equal_subset_sum PRIVATE ${leetcode_link_libraries})

