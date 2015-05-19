//
// Created by Ronald Liu on 19/5/15.
//
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";

        if (numRows==1)
            return s;

        for (int i = 0; i < numRows; i++)
        {
            int d1 = (numRows-i-1)*2;
            int d2 = i*2;
            bool isD1 = true;
            for (int j = i; j < s.size(); )
            {
                if (isD1)
                {
                    if (d1!=0)
                        result.push_back(s[j]);
                    j+=d1;
                }
                else
                {
                    if (d2!=0)
                        result.push_back(s[j]);
                    j+=d2;
                }
                isD1 = !isD1;
            }
        }

        return result;
    }
};

#include <iostream>
int main()
{
    string tmp = "PAYPALISHIRING";
    Solution s;
    cout << s.convert(tmp, 3);
    return 0;
}