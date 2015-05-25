//
// Created by Ronald Liu on 23/5/15.
//
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t tmp = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n&1)
            {
                tmp += 1;
            }
            if (i <31)
                tmp = tmp << 1;
            n = n >> 1;
        }
        return tmp;
    }
};

#include <iostream>

int main()
{
    Solution s;
    std::cout << s.reverseBits(43261596) <<std::endl;
    return 0;
}