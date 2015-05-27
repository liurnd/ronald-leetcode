//
// Created by Ronald Liu on 27/5/15.
//

#include<vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0;
        for (auto i : nums)
        {
            t = t ^ i;
        }
        return t;
    }
};

#include <iostream>
int main()
{
    Solution s;
    vector<int> t = {1,2,3,3,2};
    cout << s.singleNumber(t) << endl;
    return 0;
}