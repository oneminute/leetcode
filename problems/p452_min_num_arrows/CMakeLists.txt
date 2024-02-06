cmake_minimum_required (VERSION 3.8)

project ("p452_min_num_arrows")

add_executable(p452_min_num_arrows "sol01.cpp")
target_link_libraries(p452_min_num_arrows PRIVATE ${leetcode_link_libraries})

