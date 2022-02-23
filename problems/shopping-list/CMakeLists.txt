cmake_minimum_required (VERSION 3.8)

project ("shopping-list")

add_executable(shopping-list "sol01.cpp")
target_link_libraries(shopping-list PRIVATE ${leetcode_link_libraries})

