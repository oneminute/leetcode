cmake_minimum_required (VERSION 3.8)

project ("p679_24_game")

add_executable(p679_24_game "sol01.cpp")
target_link_libraries(p679_24_game PRIVATE ${leetcode_link_libraries})

