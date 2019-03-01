//
// Created by baz on 2019-02-20.
//

#include <vector>
#include <map>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target);
};

vector<int> Solution::twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    map<int, int> m;
    int i = 0;
    auto len = nums.size();
    for (; i < len; i++)
    {
        int temp = target - nums[i];
        auto res = m.find(temp);
        if (res != m.end())
        {
            ans.push_back(res->second);
            ans.push_back(i);
            return ans;
        }
        else
        {
            m.insert({nums[i], i});
        }
    }
    return ans;
}
