//
// Created by Ronald Liu on 17/5/15.
//

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0)
            return 0;
        for (int i = 0; i < len;)
        {
            if (nums[i] == val)
            {
                int tmp = nums[i];
                len--;
                nums[i] = nums[len];
                nums[len] = tmp;
            }
            else
                i++;
        }
        return len;
    }
};

#include <iostream>
int main()
{
    Solution s;
    vector<int> tmp = {};

    cout << s.removeElement(tmp,1) << endl;
    for (auto i: tmp)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}