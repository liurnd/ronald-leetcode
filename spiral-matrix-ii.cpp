//
// Created by Ronald Liu on 4/6/15.
//
#include <vector>

using namespace  std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> tmp(n);
        if (n == 0)
            return tmp;
        for (auto& i : tmp)
        {
            i.resize(n, 0);
        }

        int d = 0;
        int x=0, y=0;
        for (int i = 1; i <= n * n; i++)
        {
            tmp[x][y] = i;
            if (x + dx[d] < 0 || x+dx[d] >= n ||
                    y+dy[d] < 0 || y+dy[d] >= n||
                    tmp[x+dx[d]][y+dy[d]]!=0)
                d = (d +1)%4;
            x+= dx[d];
            y+= dy[d];
        }
        return tmp;
    }
};
#include <iostream>
int main()
{
    Solution s;
    for (auto& i : s.generateMatrix(0))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
