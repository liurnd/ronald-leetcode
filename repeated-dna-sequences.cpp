#include <string>
#include <unordered_map>
#include <vector>
using namespace std;



class Solution {
public:
	int push_back(int origin, char newChar)
	{
		int val = 0;
		switch (newChar)
		{
			case 'A':
				val = 0;
				break;
			case 'C':
				val = 1;
				break;
			case 'G':
				val = 2;
				break;
			case 'T':
				val = 3;
				break;
			default:
				break;
		}
		origin = (origin << 2) + val;
		return origin & 0xfffff;
	}

	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		if (s.size() < 10)
			return {};
		int hash = 0;
		unordered_map<int, int> hasSeq;
		for (int i = 0; i < 10; i++)
			hash = push_back(hash, s[i]);
		hasSeq[hash] = 1;

		for (int i = 10; i < s.size(); i++)
		{
			hash = push_back(hash, s[i]);
			if (hasSeq.count(hash) != 0){
				if (hasSeq[hash] == 1)
				{
					result.emplace_back(s, i - 9, 10);
					hasSeq[hash] = 2;
				}
			}
			else
				hasSeq[hash] = 1;
		}

		return result;
	}
};

#include <iostream>
int main()
{
	Solution s;
	auto res = s.findRepeatedDnaSequences("AAAAAAAAAAAAAAA");
	for (auto i : res)
		cout << i << endl;
	return 0;
}