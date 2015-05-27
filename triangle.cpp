//
// Created by Ronald Liu on 27/5/15.
//
#include<vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0)
            return 0;

        vector<int> ita(triangle.size(), numeric_limits<int>::max());
        ita[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = i; j > 0; j--)
            {
                ita[j] = min(ita[j], ita[j-1]);
                ita[j] += triangle[i][j];
            }
            ita[0] += triangle[i][0];
        }

        int minT = ita[0];
        for (int i = 1; i < triangle.size(); i++)
        {
            minT = min(minT, ita[i]);
        }

        return minT;
    }
};

#include <iostream>

int main()
{
    Solution s;
    vector<vector<int> > t = {{-1}, {-2,-3}};
    cout << s.minimumTotal(t) << endl;
    return 0;
}