//
// Created by Ronald Liu on 25/5/15.
//

#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        auto n = ratings.size();
        if(n == 0) return 0;

        vector<int> cnt_l(n,1);
        vector<int> cnt_r(n,1);

        for(auto i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1])
                cnt_l[i] = cnt_l[i-1]+1;
        }

        for(auto i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                cnt_r[i] = cnt_r[i+1]+1;
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += max(cnt_l[i], cnt_r[i]);
        }
        return sum;
    }
};

#include<iostream>
int main()
{
    Solution s;
    vector<int> t={2,2,4,3,3};
    cout << s.candy(t) << endl;
    return 0;
}

