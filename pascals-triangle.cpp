//
// Created by Ronald Liu on 27/5/15.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        res.emplace_back(1,1);
        for (int i = 2; i <= numRows; i++)
        {
            res.emplace_back(i, 0);
            for (int j = 1; j <= i; j++)
            {
                if (j > 1)
                    res[i-1][j-1] += res[i-2][j-2];
                if (j < i)
                    res[i-1][j-1] += res[i-2][j-1];
            }
        }
        return res;
    }
};
#include <iostream>
int main()
{
    Solution s;
    for (auto i : s.generate(0))
    {
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}