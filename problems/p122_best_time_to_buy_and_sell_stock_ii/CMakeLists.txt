cmake_minimum_required (VERSION 3.8)

project ("p122_best_time_to_buy_and_sell_stock_ii")

add_executable(p122_best_time_to_buy_and_sell_stock_ii "sol01.cpp")
target_link_libraries(p122_best_time_to_buy_and_sell_stock_ii PRIVATE ${leetcode_link_libraries})

