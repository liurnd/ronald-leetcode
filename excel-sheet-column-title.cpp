//
// Created by Ronald Liu on 3/6/15.
//
#include <string>

using namespace std;
class Solution2 {
public:
    int titleToNumber(string s) {
        int col = 0;
        for (auto i : s)
        {
            col *= 26;
            int t = i - 'A' + 1;
            col += t;
        }
        return col;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string tmp;
        if (n == 0)
            return "A";
        while (n != 0)
        {
            int t = n % 26;
            if (t == 0)
            {
                n--;
                t = 26;
            }

            tmp +=  ('A'+t-1);
            n = n / 26;
        }
        std::reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};
#include <iostream>
#include <cassert>
int main()
{
    for (int i = 1; i < 1024; i++)
    {
        Solution s;
        Solution2 s1;
        assert(s1.titleToNumber(s.convertToTitle(i)) == i);
    }
    return 0;
}