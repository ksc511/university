cmake_minimum_required(VERSION 4.0)
project(assignment3)

set(CMAKE_CXX_STANDARD 23)

add_executable(assignment3 main.cpp
        Article.cpp
        Article.h
        Stock.cpp
        Stock.h)
