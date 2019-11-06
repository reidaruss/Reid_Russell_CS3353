cmake_minimum_required(VERSION 3.14)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp Node.cpp Node.h fileIn.cpp fileIn.h Algorithm.h bruteTSP.cpp bruteTSP.h TSP.cpp TSP.h DPTSP.cpp DPTSP.h)