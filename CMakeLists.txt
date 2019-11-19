include_directories(.)

# cmake_minimum_required(VERSION <specify CMake version here>)
project(Assignment4)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        assign4
        main.cpp
        buffer.cpp
        buffer.h)