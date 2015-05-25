//
// Created by Ronald Liu on 24/5/15.
//

#include <string.h>
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int *f = new int[s.size()];
        memset(f, 0, sizeof(int)*s.size());
        stack<int> leftStack;
        for (int i = 0; i < s.size();i++)
        {
            if (s[i] == '(')
                leftStack.push(i);
            else
            {
                if (leftStack.empty())
                    continue;
                int lastL = leftStack.top();
                leftStack.pop();
                f[i] = i - lastL + 1;
                if (lastL!=0)
                    f[i] += f[lastL-1];
            }
        }

        int max = 0;
        for (int i = 0; i < s.size(); i++)
            if (f[i] > max)
                max = f[i];
        return max;
    }
};

#include <iostream>
int main()
{
    Solution s;
    cout << s.longestValidParentheses(")()()(((((()))") << endl;
    return 0;
}