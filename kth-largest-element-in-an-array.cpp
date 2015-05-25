//
// Created by Ronald Liu on 24/5/15.
//

#include <vector>
using namespace std;

class Solution {
public:
    int iter(vector<int>& nums, int l, int r, int k)
    {
        int i = l, j = r, pri = nums[l];
        while(i<j)
        {
            while (nums[j] < pri && i < j) j--;
            if (i < j)
            {
                nums[i] = nums[j];
                i++;
            }
            while (nums[i] >= pri && i < j) i++;
            if (i<j)
            {
                nums[j] = nums[i];
                j--;
            }
        }
        nums[i] = pri;

        if (k > i)
        {
            return iter(nums, i+1, r, k);
        }
        else if (k < i)
        {
            return iter(nums, l, i-1, k);
        }
        return nums[i];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return iter(nums, 0, nums.size()-1, k-1);
    }
};

#include <iostream>
int main()
{
    vector<int> tmp = {3,2,1,5,6,4};
    Solution s;
    cout <<  s.findKthLargest(tmp, 1) << endl;
    return 0;
}