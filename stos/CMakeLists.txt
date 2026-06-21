cmake_minimum_required(VERSION 4.0)
project(stos)

set(CMAKE_CXX_STANDARD 20)

add_executable(stos main.cpp
        stack.cpp
        stack.h)
