
cmake_minimum_required(VERSION 3.7)

project(Pong)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Pong src/main.cc)