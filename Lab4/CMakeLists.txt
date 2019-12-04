cmake_minimum_required(VERSION 3.13)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab4 src/main.cpp src/Algorithm.h src/Node.cpp src/Node.h src/TSP.cpp src/TSP.h src/file.cpp src/file.h src/GA.cpp src/GA.h src/Individual.cpp src/Individual.h src/main.cpp src/Tabu.cpp src/Tabu.h src/Neighbor.cpp src/Neighbor.h)