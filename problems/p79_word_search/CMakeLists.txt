cmake_minimum_required (VERSION 3.8)

project ("p79_word_search")

add_executable(p79_word_search "sol01.cpp")
target_link_libraries(p79_word_search PRIVATE ${leetcode_link_libraries})

