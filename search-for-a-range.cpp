//
// Created by Ronald Liu on 29/5/15.
//

#include <vector>
using namespace std;

class Solution {
public:
    int findFirstTarget(const vector<int>& nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if (nums[mid]<target)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        if (nums[l] == target)
            return l;
        if (nums[r] == target)
            return r;

        return -1;
    }

    int findLastTarget(const vector<int>& nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if (nums[mid]<=target)
            {
                l = mid;
            }
            else
            {
                r = mid-1;
            }
            if (l == r-1)
            {
                if (nums[r] == target)
                    return r;
                if (nums[l] == target)
                    return l;
            }
        }
        if (nums[l] == target)
            return l;
        if (nums[r] == target)
            return r;

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0)
            return {-1, -1};
        int fI = findFirstTarget(nums, target);
        if (fI == -1)
            return {-1, -1};
        int fL = findLastTarget(nums, target);
        return {fI, fL};
    }
};


#include <iostream>
int main()
{
    Solution s;
    vector<int> a = {1,1,1,1,1};
    vector<int> res = s.searchRange(a, 1);
    cout <<res[0] << " "<<res[1]<< endl;
    return 0;
}
