//
// Created by Ronald Liu on 24/4/15.
//

#include <cassert>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool *tRes = new bool[s.length()+1];
        memset(tRes, false, sizeof(bool)*(s.length()+1));

        bool *res = tRes+1;
        res[-1] = true;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = -1; j < i; j++)
            {
                if (res[j] && wordDict.count(s.substr(j+1, i-j)))
                {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[s.size()-1];
    }
};

int main()
{
    Solution s;
    unordered_set<string> list = {"leet", "code"};
    assert(s.wordBreak("leetcode", list));
    assert(s.wordBreak("codeleetcode1", list)==false);


    unordered_set<string> list2 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    assert(s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", list2) == false);
    return 0;
}
