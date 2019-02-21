cmake_minimum_required(VERSION 3.13)
project(algo)

set(CMAKE_CXX_STANDARD 14)

add_executable(algo main.cpp
        util/Util.h easy/TwoSum_1.h
        util/PrimitiveDataTypeSizes.h
        medium/AddTwoNumbers_2.h
        easy/ReverseInteger_7.h
        easy/PalindromeNumber_9.h)