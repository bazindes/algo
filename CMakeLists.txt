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

        lc/easy/TwoSum_1.cpp
        lc/easy/ReverseInteger_7.cpp
        lc/easy/PalindromeNumber_9.cpp
        lc/easy/RomanToInteger_13.cpp
        lc/easy/LongestCommonPrefix_14.cpp
        lc/easy/ValidParentheses_20.cpp
        lc/easy/MergeTwoSortedLists_21.cpp
        lc/easy/RemoveDuplicatesFromSortedArray_26.cpp
        lc/easy/RemoveElement_27.cpp
        lc/easy/ImplementstrStr_28.cpp
        lc/easy/SearchInsertPosition_35.cpp
        lc/easy/CountAndSay_38.cpp
)
