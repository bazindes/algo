cmake_minimum_required(VERSION 3.13)
project(algo)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        algo 
        main.cpp
        util/mtype/ListNode.cpp
        prac/PrimitiveDataTypeSizes.cpp
        prac/HeapAndStackMem.c
        prac/StructUnionEnum.c

        easy/TwoSum_1.cpp
        easy/ReverseInteger_7.cpp
        easy/PalindromeNumber_9.cpp
        easy/RomanToInteger_13.cpp
        easy/LongestCommonPrefix_14.cpp
        easy/ValidParentheses_20.cpp
        easy/MergeTwoSortedLists_21.cpp
        easy/RemoveDuplicatesFromSortedArray_26.cpp
        easy/RemoveElement_27.cpp
        easy/ImplementstrStr_28.cpp
        easy/SearchInsertPosition_35.cpp
        easy/CountAndSay_38.cpp

        )
