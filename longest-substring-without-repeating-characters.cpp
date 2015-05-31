//
// Created by Ronald Liu on 27/5/15.
//
#include <string>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0)
            return 0;
        int lastOffset[256];
        for (int i = 0; i < 256; i++)
            lastOffset[i] = -1;
        int tMax = 0;
        int curStart = 0;
        int curLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tMax < curLen)
                tMax = curLen;
            if (lastOffset[s[i]] < curStart)
            {
                curLen++;
            }
            else
            {
                curLen -= lastOffset[s[i]] - curStart;
                curStart = lastOffset[s[i]] + 1;
            }

            lastOffset[s[i]] = i;
        }

        if (tMax < curLen)
            tMax = curLen;
        return tMax;
    }
};

#include <iostream>

int main()
{
    Solution s;
    string a = "abba";

    cout << s.lengthOfLongestSubstring(a) << endl;

    return 0;
}