//
// Created by Ronald Liu on 1/6/15.
//
#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        bool canDo[s1.size()+1][s1.size()][s1.size()];
        memset(canDo, false, sizeof(canDo));
        for (int l = 1; l <= s1.size(); l++)
        {
            for (int i = 0; i <= s1.size()-l; i++)
            {
                for (int j = 0; j <= s1.size()-l; j++)
                {
                    bool res = true;
                    for (int k = 0; k < l; k++)
                    {
                        if (s1[i+k] != s2[j+k])
                        {
                            res = false;
                            break;
                        }
                    }
                    if (res)
                        canDo[l][i][j] = true;
                    else
                    {
                        for (int lp = 1; lp < l; lp++)
                        {
                            if ((canDo[lp][i][j+(l-lp)] && canDo[l-lp][i+lp][j]) || (canDo[lp][i][j] && canDo[l-lp][i+lp][j+lp]))
                            {
                                res = true;
                                break;
                            }
                        }

                        canDo[l][i][j] = res;
                    }
                }
            }
        }
        return canDo[s1.size()][0][0];
    }
};

#include <cassert>
int main()
{
    Solution s;

    assert(s.isScramble("abc", "abc"));
    assert(!s.isScramble("rgtaf", "great"));
    assert(s.isScramble("rgtae", "great"));
    assert(s.isScramble("a", "a"));
    assert(!s.isScramble("rgtaf", "great"));
    assert(s.isScramble("rgtae", "great"));

    return 0;
}