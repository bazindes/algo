cmake_minimum_required(VERSION 3.14)

project(algo LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "Cmake")

add_executable(
        algo 
        src/main.cpp
        src/util/pch.cpp
        src/ds/list/LinkedList.cpp
        src/ds/list/DoubleLinkedList.cpp
        src/ds/tree/BinaryTree.cpp
        src/ds/graph/Graph.cpp
)

