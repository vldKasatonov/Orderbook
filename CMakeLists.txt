cmake_minimum_required(VERSION 3.31)
project(Orderbook)

set(CMAKE_CXX_STANDARD 20)

add_executable(Orderbook
        src/main.cpp
        src/Orderbook.cpp
        src/Orderbook.h
        src/Order.cpp
        src/Order.h)
