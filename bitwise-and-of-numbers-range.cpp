//
// Created by Ronald Liu on 27/5/15.
//


class Solution {
public:
    bool rangeBit(int m, int n, int pos)
    {
        unsigned int testB = 1u << pos;
        if (((m & testB) == 0) || ((n & testB) == 0))
            return false;
        if (n-m > testB)
            return false;
        return true;
    }
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for (int i = 31; i >=0 ; i--)
        {
            res = (res << 1);
            res += rangeBit(m,n,i)? 1:0;
        }
        return res;
    }
};

#include <iostream>
int main()
{
    Solution s;
    std::cout << s.rangeBitwiseAnd(4,5) << std::endl;
    return 0;
}
