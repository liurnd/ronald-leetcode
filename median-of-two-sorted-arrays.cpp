//
// Created by Ronald Liu on 14/5/15.
//
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:

    int findIdx(int target, const vector<int>& nums)
    {
        int t = nums.size()-1;
        int h = 0u;
        return findIdx(target, h, t, nums);
    }

    int findIdx(int target,int h, int t, const vector<int>& nums)
    {
        if (nums.size()==0)
            return -1;
        while (h < t)
        {
            auto mid = (h+t) / 2;
            if (nums[mid] <= target){
                h = mid+1;
            }
            else
            {
                t = mid-1;
            }
        }
        if (nums[h] > target)
            return h-1;
        return h;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};

int main()
{
    Solution s;
    auto target = 6;
    vector<int> tmp = {};
    auto idx = s.findIdx(target, tmp);
    assert(idx == -1 || (tmp[idx]<=target && ((idx == tmp.size()-1) || tmp[idx+1] > target)));
    return 0;
}
