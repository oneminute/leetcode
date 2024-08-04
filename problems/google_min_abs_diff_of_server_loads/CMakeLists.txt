cmake_minimum_required (VERSION 3.8)

project ("google_min_abs_diff_of_server_loads")

add_executable(google_min_abs_diff_of_server_loads "sol01.cpp")
target_link_libraries(google_min_abs_diff_of_server_loads PRIVATE ${leetcode_link_libraries})

