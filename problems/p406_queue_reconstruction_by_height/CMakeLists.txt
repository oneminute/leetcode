cmake_minimum_required (VERSION 3.8)

project ("p406_queue_reconstruction_by_height")

add_executable(p406_queue_reconstruction_by_height "sol01.cpp")
target_link_libraries(p406_queue_reconstruction_by_height PRIVATE ${leetcode_link_libraries})

