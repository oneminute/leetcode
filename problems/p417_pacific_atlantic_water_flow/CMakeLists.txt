cmake_minimum_required (VERSION 3.8)

project ("p417_pacific_atlantic_water_flow")

add_executable(p417_pacific_atlantic_water_flow "sol01.cpp")
target_link_libraries(p417_pacific_atlantic_water_flow PRIVATE ${leetcode_link_libraries})

