cmake_minimum_required (VERSION 3.8)

project ("p695_max_area_of_island")

add_executable(p695_max_area_of_island "sol01.cpp")
target_link_libraries(p695_max_area_of_island PRIVATE ${leetcode_link_libraries})

