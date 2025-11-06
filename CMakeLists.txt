cmake_minimum_required(VERSION 4.0)
project(Assignment3)

set(CMAKE_CXX_STANDARD 23)

add_executable(Assignment3 main.cpp
        Stock.h
        Article.h
        Article.cpp
        Stock.cpp)
