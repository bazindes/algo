cmake_minimum_required(VERSION 3.13)
project(algo)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        algo main.cpp
        util/Util.h 
#        util/PrimitiveDataTypeSizes.h

#        easy/TwoSum_1.h
#        easy/ReverseInteger_7.h
#        easy/PalindromeNumber_9.h
#        easy/RomanToInteger_13.h
#        easy/LongestCommonPrefix_14.h
#        easy/ValidParentheses_20.h
#        easy/MergeTwoSortedLists_21.h
#        easy/RemoveDuplicatesFromSortedArray_26.h
#        easy/RemoveElement_27.h
        # easy/ImplementstrStr_28.h
#        easy/SearchInsertPosition_35.h
        easy/CountAndSay_38.h

#        medium/AddTwoNumbers_2.h
        )
