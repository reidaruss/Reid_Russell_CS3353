cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        algorithm.h
        bubble.cpp
        bubble.h
        datagen.cpp
        datagen.h
        insertion.cpp
        insertion.h
        main.cpp
        merge.cpp
        merge.h
        sort.cpp
        sort.h)
