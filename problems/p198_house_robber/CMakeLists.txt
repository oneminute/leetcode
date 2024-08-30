cmake_minimum_required (VERSION 3.8)

project ("p198_house_robber")

add_executable(p198_house_robber "sol01.cpp")
target_link_libraries(p198_house_robber PRIVATE ${leetcode_link_libraries})

