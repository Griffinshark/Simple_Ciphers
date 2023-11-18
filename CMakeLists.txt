cmake_minimum_required(VERSION 3.26)
project(Simple_Ciphers)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimpleCiphers Source/main.cpp
        Source/brute_force.h
        Source/brute_force.cpp
        Source/ciphers.h
        Source/ciphers.cpp
)
