cmake_minimum_required(VERSION 3.21)
project(task11)

set(CMAKE_CXX_STANDARD 14)

add_executable(task11 main.cpp train.cpp train.h transport.cpp transport.h ship.cpp ship.h plane.cpp plane.h rnd.h container.cpp container.h)
