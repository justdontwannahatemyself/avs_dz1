cmake_minimum_required(VERSION 3.20)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp fish.cpp fish.h bird.h bird.cpp beast.cpp beast.h animals.h animals.cpp container.cpp container.h)