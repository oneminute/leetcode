cmake_minimum_required (VERSION 3.8)

project ("p605_can_place_flowers")

add_executable(p605_can_place_flowers "sol01.cpp")
target_link_libraries(p605_can_place_flowers PRIVATE ${leetcode_link_libraries})

