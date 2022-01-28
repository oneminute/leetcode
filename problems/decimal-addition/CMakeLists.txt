cmake_minimum_required (VERSION 3.8)

project ("decimal-addition")

add_executable(decimal-additions "sol01.cpp")
target_link_libraries(decimal-additions PRIVATE ${leetcode_link_libraries})
