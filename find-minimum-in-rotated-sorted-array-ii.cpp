//
// Created by Ronald Liu on 26/4/15.
//
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findMin(const vector<int>& nums,const int first, size_t left, size_t right)
    {
        if (left == right)
            return nums[left];
        if (left+1 == right)
            return min(nums[left], nums[right]);
        size_t mid = (left+right)/2;
        if (nums[mid]>first)
            return findMin(nums, first, mid+1, right);
        else if (nums[mid] < first)
            return findMin(nums, first, left, mid);
        else
            return min(findMin(nums,first,left, mid-1), findMin(nums, first, mid+1, right));
    }
    int findMin(vector<int>& nums) {
        auto res = findMin(nums,nums[0], 0, nums.size()-1);
        return res<nums[0]?res:nums[0];
    }
};

int main()
{
    Solution s;
    vector<int> t1 = {10,1,10,10,10};
    printf("%d\n", s.findMin(t1));
    return 0;
}