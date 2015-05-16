//
// Created by Ronald Liu on 14/5/15.
//

#include <vector>
#include <string>


using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> ann = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        k--;
        vector<char> b = {'1','2','3','4','5','6','7','8','9'};
        string res;
        for (int i = n-1; i >=0; i--) {
            int a = k / ann[i];
            k = k % ann[i];
            res.push_back(b[a]);
            b.erase(b.begin()+a);
        }
        return res;
    }
};
#include <iostream>
int main()
{
    Solution s;
    cout << s.getPermutation(3,5) << endl;
    return 0;
}