cmake_minimum_required(VERSION 3.20)
project(mpi_mag)

set(CMAKE_CXX_STANDARD 14)

add_executable(mpi_mag main.cpp maharaja.h maharaja.cpp)
