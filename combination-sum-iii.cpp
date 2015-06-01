//
// Created by Ronald Liu on 31/5/15.
//
#include <vector>

using namespace std;

class Solution {
public:

    int maxSum[10] = {0, 45, 44, 42, 39, 35, 30, 24, 17, 9};
    void fvCk(int i, int k, int n, vector<bool>& mask, vector<vector<int>>& resultList)
    {
        if (i > 10)
            return;
        if (n < 0)
            return;
        if (maxSum[i] < n)
            return;
        if (k==0)
        {
            if (n != 0)
                return;
            vector<int> tmp;
            for (int v = 1; v <= 9; v++) {
                if (mask[v])
                    tmp.push_back(v);
            }
            resultList.push_back(tmp);
            return ;
        }

        mask[i] = true;
        fvCk(i+1, k-1, n-i, mask ,resultList);
        mask[i] = false;
        fvCk(i+1, k, n, mask, resultList);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> mask(10, false);
        vector<vector<int>> resultList;
        fvCk(1, k, n, mask, resultList);
        return resultList;
    }
};

#include <iostream>

int main()
{
    Solution s;
    vector<vector<int>>  res = s.combinationSum3(3,15);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}