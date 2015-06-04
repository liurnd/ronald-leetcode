//
// Created by Ronald Liu on 4/6/15.
//
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int nm = matrix.size()-1;
        for (int x = 0; x < (matrix.size()+1) / 2; x++)
        {
            for (int y = 0; y < (matrix.size())/2; y++ )
            {
                int x1 = nm - y, y1 = x;
                int x2 = nm-x, y2 = nm-y;
                int x3 = y, y3 = nm-x;

                swap(matrix[x2][y2], matrix[x1][y1]);
                swap(matrix[x3][y3], matrix[x2][y2]);
                swap(matrix[x][y], matrix[x3][y3]);
            }
        }
    }
};

#include <iostream>
int main()
{
    vector<vector<int>> matrix = {};
    Solution s;
    s.rotate(matrix);
    for (auto& i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}