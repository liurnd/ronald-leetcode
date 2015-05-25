//
// Created by Ronald Liu on 25/5/15.
//
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int *df = new int[prices.size()];
        int pre = 0;
        int max = 0;
        df[0] = 0;
        for (int i = 1 ;i < prices.size(); i++)
            df[i] = prices[i] - prices[i-1];

        for (int i = 1; i < prices.size(); i++)
        {
            int tMax = pre+df[i];
            tMax = tMax>df[i]?tMax:df[i];
            pre = tMax>0?tMax:0;
            max = tMax>max?tMax:max;
        }

        return max;
    }
};

#include <iostream>
int main()
{
    Solution s;
    vector<int> t = {1,2,3,4,5,6,2,13};
    cout << s.maxProfit(t) << endl;
    return 0;
}