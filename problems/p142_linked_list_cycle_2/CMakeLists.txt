cmake_minimum_required (VERSION 3.8)

project ("p142_linked_list_cycle_2")

add_executable(p142_linked_list_cycle_2 "sol01.cpp")
target_link_libraries(p142_linked_list_cycle_2 PRIVATE ${leetcode_link_libraries})

