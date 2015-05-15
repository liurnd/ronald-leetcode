//
// Created by Ronald Liu on 12/5/15.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<int,int> num_set;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size();i++)
        {
            num_set[nums[i]] = i;
        }

        for (int i = 0; i < nums.size();i++)
        {
            int fT = target-nums[i];
            if (num_set.count(fT) && num_set[fT]!=i)
            {
                return {i+1, num_set[fT]+1};
            }
        }
    }
};
#include <iostream>
int main()
{
    vector<int> t = {3, 2, 4,11,13,15};
    Solution s;
    auto res = s.twoSum( t, 6);
    cout << res[0] << " " << res[1] << endl;
}