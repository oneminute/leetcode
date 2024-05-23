cmake_minimum_required (VERSION 3.8)

project ("p51_n_queens")

add_executable(p51_n_queens "sol01.cpp")
target_link_libraries(p51_n_queens PRIVATE ${leetcode_link_libraries})

