cmake_minimum_required (VERSION 3.8)

project ("p121_best_time_to_buy_and_sell_stock")

add_executable(p121_best_time_to_buy_and_sell_stock "sol01.cpp")
target_link_libraries(p121_best_time_to_buy_and_sell_stock PRIVATE ${leetcode_link_libraries})

