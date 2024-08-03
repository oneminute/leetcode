cmake_minimum_required (VERSION 3.8)

project ("p11_container_with_most_water")

add_executable(p11_container_with_most_water "sol01.cpp")
target_link_libraries(p11_container_with_most_water PRIVATE ${leetcode_link_libraries})

