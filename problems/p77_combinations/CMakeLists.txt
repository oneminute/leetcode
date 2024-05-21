cmake_minimum_required (VERSION 3.8)

project ("p77_combinations")

add_executable(p77_combinations "sol01.cpp")
target_link_libraries(p77_combinations PRIVATE ${leetcode_link_libraries})

