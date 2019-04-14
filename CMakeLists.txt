cmake_minimum_required(VERSION 3.14)
project(algo LANGUAGES CXX)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

# version
set(ALGO_VERSION_MAJOR 1)
set(ALGO_VERSION_MINOR 0)
set(ALGO_VERSION_PATCH 0)
set(ALGO_VERSION "${ALGO_VERSION_MAJOR}.${ALGO_VERSION_MINOR}.${ALGO_VERSION_PATCH}")
message(STATUS "You are compiling: algo ${ALGO_VERSION}")

# add_subdirectory(tests)
# set(BASIC 
# src/util/pch.cpp
# src/algo.cpp
# src/ds/list/LinkedList.cpp
# src/ds/list/DoubleLinkedList.cpp
# src/ds/graph/Graph.cpp
# src/ds/tree/BinaryTree.cpp
# )

auto_sources(files "*.cpp" "RECURSE" "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(algo 
# ${BASIC}
)