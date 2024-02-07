cmake_minimum_required (VERSION 3.8)

project ("p763_partition_labels")

add_executable(p763_partition_labels "sol01.cpp")
target_link_libraries(p763_partition_labels PRIVATE ${leetcode_link_libraries})

