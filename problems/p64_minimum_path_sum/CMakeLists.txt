cmake_minimum_required (VERSION 3.8)

project ("p64_minimum_path_sum")

add_executable(p64_minimum_path_sum "sol01.cpp")
target_link_libraries(p64_minimum_path_sum PRIVATE ${leetcode_link_libraries})

