cmake_minimum_required(VERSION 3.14)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 main.cpp Search.cpp Search.h algorithm.h LinkedList.h DFS.cpp DFS.h BFS.cpp BFS.h Dijkstra.cpp Dijkstra.h AStar.cpp AStar.h AdjacencyList.h Path.cpp Path.h)