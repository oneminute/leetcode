cmake_minimum_required (VERSION 3.8)

project ("rows-statictics")

add_executable(rows-statictics "sol01.cpp")
target_link_libraries(rows-statictics PRIVATE ${leetcode_link_libraries})
