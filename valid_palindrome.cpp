//
// Created by Ronald Liu on 12/5/15.
//

#include<cctype>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()==0)
            return true;
        if (s.size()==1)
            return true;
        int p1 = 0, p2 = s.size()-1;
        while(p1<p2)
        {
            if (!isalpha(s[p1]) && !isdigit(s[p1])){p1++;continue;}
            if (!isalpha(s[p2]) && !isdigit(s[p2])){p2--;continue;}
            if (toupper(s[p1]) != toupper(s[p2]))
                return false;
            p1++;p2--;
        }

        return true;
    }
};
#include <cassert>
int main()
{
    Solution s;
    assert(!s.isPalindrome("ab"));
    assert(s.isPalindrome("1bab1"));
    return 0;
}