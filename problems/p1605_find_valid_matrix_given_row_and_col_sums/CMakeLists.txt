cmake_minimum_required (VERSION 3.8)

project ("p1605_find_valid_matrix_given_row_and_col_sums")

add_executable(p1605_find_valid_matrix_given_row_and_col_sums "sol01.cpp")
target_link_libraries(p1605_find_valid_matrix_given_row_and_col_sums PRIVATE ${leetcode_link_libraries})

