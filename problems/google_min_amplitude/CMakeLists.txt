cmake_minimum_required (VERSION 3.8)

project ("google_min_amplitude")

add_executable(google_min_amplitude "sol01.cpp")
target_link_libraries(google_min_amplitude PRIVATE ${leetcode_link_libraries})

