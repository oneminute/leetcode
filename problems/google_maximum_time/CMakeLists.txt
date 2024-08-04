cmake_minimum_required (VERSION 3.8)

project ("google_maximum_time")

add_executable(google_maximum_time "sol01.cpp")
target_link_libraries(google_maximum_time PRIVATE ${leetcode_link_libraries})

