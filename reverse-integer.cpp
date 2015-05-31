//
// Created by Ronald Liu on 27/5/15.
//
#include <limits>
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int largestHead = std::numeric_limits<int>::max() / 10;
        int smallHead = std::numeric_limits<int>::min() / 10;
        while(x  != 0)
        {
            if (res > largestHead || res < smallHead)
                return 0;
            res *= 10;
            res += x%10;
            x = x / 10;
        }

        return res;
    }
};

#include <iostream>

int main()
{
    Solution s;
    std::cout << s.reverse(3000001) << std::endl;
    return 0;
}
