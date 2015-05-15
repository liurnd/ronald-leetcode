#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string tmp;
		if (strs.size() == 0)
			return tmp;
		if (strs.size() == 1)
			return strs[0];
		for (int ptr = 0; true; ptr++)
		{
			char at = '\0';
			bool match = true;
			for (auto i : strs)
			{
				if (at == '\0')
				{
					if (ptr >= i.size())
					{
						match = false;
						break;
					}
					at = i[ptr];
				}
				else
					if (ptr >= i.size() || i[ptr] != at)
					{
						match = false;
						break;
					}
			}

			if (!match)
				break;
			tmp.push_back(at);
		}
		return tmp;
	}
};
#include <iostream>

int main()
{
	Solution s;
	vector<string> tmp = { "ab", "" };
	cout << s.longestCommonPrefix(tmp) << endl;
	return 0;
}