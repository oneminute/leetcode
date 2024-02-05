cmake_minimum_required (VERSION 3.8)

project ("p135_candy")

add_executable(p135_candy "sol01.cpp")
target_link_libraries(p135_candy PRIVATE ${leetcode_link_libraries})

