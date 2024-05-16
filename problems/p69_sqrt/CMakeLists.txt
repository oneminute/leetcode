cmake_minimum_required (VERSION 3.8)

project ("p69_sqrt")

add_executable(p69_sqrt "sol01.cpp")
target_link_libraries(p69_sqrt PRIVATE ${leetcode_link_libraries})

