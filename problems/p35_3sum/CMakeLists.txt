cmake_minimum_required (VERSION 3.8)

project ("p35_3sum")

add_executable(p35_3sum "sol01.cpp")
target_link_libraries(p35_3sum PRIVATE ${leetcode_link_libraries})

