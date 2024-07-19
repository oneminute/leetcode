cmake_minimum_required (VERSION 3.8)

project ("p1111_delete_nodes_return_forest")

add_executable(p1111_delete_nodes_return_forest "sol01.cpp")
target_link_libraries(p1111_delete_nodes_return_forest PRIVATE ${leetcode_link_libraries})

