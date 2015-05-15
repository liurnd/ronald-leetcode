#include <vector>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1);
		result[0] = 1;
		for (int i = 0; i <= rowIndex; i++)
		{
			for (int j = i; j > 0; j--)
			{
				result[j] = result[j] + result[j - 1];
			}
		}
		return result;
	}
};

#include <iostream>
int main()
{
	Solution s;
	auto result = s.getRow(3);
	for (auto i : result)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}