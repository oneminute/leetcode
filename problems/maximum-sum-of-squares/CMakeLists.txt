cmake_minimum_required (VERSION 3.8)

project ("maximum-sum-of-squares")

add_executable(maximum-sum-of-squares-sol1 "sol01.cpp")
target_link_libraries(maximum-sum-of-squares-sol1 PRIVATE ${leetcode_link_libraries})

add_executable(maximum-sum-of-squares-sol2 "sol02.cpp")
target_link_libraries(maximum-sum-of-squares-sol2 PRIVATE ${leetcode_link_libraries})

