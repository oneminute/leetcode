cmake_minimum_required (VERSION 3.8)

project ("p547_number_of_provinces")

add_executable(p547_number_of_provinces "sol01.cpp")
target_link_libraries(p547_number_of_provinces PRIVATE ${leetcode_link_libraries})

