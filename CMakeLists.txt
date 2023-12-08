cmake_minimum_required(VERSION 3.26)
project(ptrees)

set(CMAKE_CXX_STANDARD 17)

add_library(ptrees SHARED src/PTree.cpp
        src/PTree.h
        src/PTree.cpp
)
