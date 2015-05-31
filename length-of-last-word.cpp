//
// Created by Ronald Liu on 29/5/15.
//
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=-1, r=-1;
        int state = 0;
        for (int i = 0 ; i < s.size(); i++)
        {
            if (state == 0)
            {
                if (s[i] == ' ') state = 1;
                else {l = i; r = i; state = 2;}
            }else if (state == 1)
            {
                if (s[i] == ' ') ;
                else {l = i; r = i; state = 2;}
            } if (state == 2)
            {
                if (s[i] == ' ') state = 1;
                else r = i;
            }
        }
        if (l==-1)
            return 0;
        return r-l+1;
    }
};

#include <iostream>
int main()
{
    Solution s;

    cout << s.lengthOfLastWord("  e     e");
    return 0;
}