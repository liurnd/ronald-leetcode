//
// Created by Ronald Liu on 3/6/15.
//
#include <string>
using namespace std;
class Solution {
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
#include <cassert>
int main()
{
    Solution s;
    assert(s.titleToNumber("AB")==28);
    assert(s.titleToNumber("Z")==26);
    return 0;
}