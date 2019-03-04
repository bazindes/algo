// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,2,2,3,3,4],

// Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

// It doesn't matter what values are set beyond the returned length.
// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

// Internally you can think of this:

// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);

// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

#include <iostream>
#include <vector>

using namespace std;

class RemoveDuplicatesFromSortedArray_26
{
  public:
    int removeDuplicates(vector<int> &nums);
    int removeDuplicates_(vector<int> &nums);
    void test();
};

//O(n) O(1)
int RemoveDuplicatesFromSortedArray_26::removeDuplicates(vector<int> &nums)
{
    int ans = 0;
    if (!nums.size())
    {
        return ans;
    }

    int i = 0;
    int j = 1;
    for (; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
            ans++;
        }
    }

    return ans + 1;
}

int RemoveDuplicatesFromSortedArray_26::removeDuplicates_(vector<int> &nums)
{
    return 0;
}

void RemoveDuplicatesFromSortedArray_26::test()
{
    vector<int> v1 = {1, 1, 2};
    vector<int> v2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << endl
         << removeDuplicates(v1) << endl;
    for (auto i = v1.begin(); i < v1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl
         << removeDuplicates(v2) << endl;
    for (auto i = v2.begin(); i < v2.end(); i++)
    {
        cout << *i << " ";
    }
}
