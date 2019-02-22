// Given an array nums and a value val, remove all instances of that value in-place and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example 1:

// Given nums = [3,2,2,3], val = 3,

// Your function should return length = 2, with the first two elements of nums being 2.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,1,2,2,3,0,4,2], val = 2,

// Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

// Note that the order of those five elements can be arbitrary.

// It doesn't matter what values are set beyond the returned length.
// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

// Internally you can think of this:

// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeElement(nums, val);

// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int removeElement(vector<int>& nums, int val);
        int removeElement_(vector<int>& nums, int val);
        void test();
};

//O(n) O(1)
int Solution::removeElement(vector<int> & nums, int val){
    if(!nums.size()) {
        return 0;
    }
    int i = 0;
    int j = nums.size() - 1;
    while(1){
        while(i < nums.size() && nums[i] != val){ i ++; }
        while(j && nums[j] == val){ j --; }
        if(i >= j){ break; }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i ++;
        j --;
        
    }
    return i;
}

int Solution::removeElement_(vector<int> & nums, int val){

    return 0;
}

void Solution::test(){
    vector<int> v1 = {3,2,2,3};
    vector<int> v2 = {0,1,2,2,3,0,4,2};

    cout << removeElement(v1, 2) << endl;
    for(auto i=v1.begin(); i<v1.end(); i++){ cout << *i << " "; };
    cout << endl << removeElement(v2, 2) << endl;
    for(auto i=v2.begin(); i<v2.end(); i++){ cout << *i << " "; };
}