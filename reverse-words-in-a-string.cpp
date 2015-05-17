#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        stack<pair<size_t, size_t> > posStack;
        string tmpS;

        for (size_t i = 0; i < s.size(); i++)
        {
            for (; i < s.size() && s[i]==' '; i++);
            if (i >= s.size())
                break;

            size_t i1 = i;

            size_t j;
            for (j = 1 ; i+j < s.size() && s[i+j]!=' '; j++);

            posStack.push(make_pair(i1, j));
            i += j;
        }

        while(!posStack.empty())
        {
            auto pos1 = posStack.top();
            tmpS.append(s, pos1.first, pos1.second);
            posStack.pop();
            if (posStack.empty())
                break;
            else
                tmpS.push_back(' ');
        }
        s = tmpS;
    }
};

#include <iostream>
int main()
{
    Solution s;
    string tmp  = "    ";
    s.reverseWords(tmp);
    cout << tmp;
    return 0;
}
