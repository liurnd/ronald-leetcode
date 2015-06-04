//
// Created by Ronald Liu on 2/6/15.
//

class Solution {
public:
    int numTrees(int n) {
        int f[1024] = {0};
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = 0;
            for (int j = 0; j < i; j++)
            {
                int rn = i - j - 1;
                f[i] += f[j] * f[rn];
            }
        }
        return f[n];
    }
};

#include <cassert>

int main()
{
    Solution s;
    assert(s.numTrees(3)==5);
    return 0;
}