cmake_minimum_required (VERSION 3.8)

project ("p76_minimum_window_substring")

add_executable(p76_minimum_window_substring "sol01.cpp")
target_link_libraries(p76_minimum_window_substring PRIVATE ${leetcode_link_libraries})

