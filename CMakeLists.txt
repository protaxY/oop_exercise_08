cmake_minimum_required(VERSION 3.17)
project(OOP_lp8)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-pthread")

add_executable(OOP_lp8 main.cpp Figure.cpp Figure.h Cord.cpp Cord.h Pentagon.cpp Pentagon.h Hexagon.cpp Hexagon.h Octagon.cpp Octagon.h)
