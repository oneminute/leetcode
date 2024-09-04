cmake_minimum_required (VERSION 3.8)

project ("p91_decode_ways")

add_executable(p91_decode_ways "sol01.cpp")
target_link_libraries(p91_decode_ways PRIVATE ${leetcode_link_libraries})

