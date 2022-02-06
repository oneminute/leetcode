cmake_minimum_required (VERSION 3.8)

project ("validate-ip-address")

add_executable(validate-ip-address "sol01.cpp")
target_link_libraries(validate-ip-address PRIVATE ${leetcode_link_libraries})
