//
// Created by Ronald Liu on 26/4/15.
//

#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    void doit(const vector<int>& src,int lookupPtr, int selectLen, int* selectArray, const function<void(int*, int)> finish)
    {
        if (lookupPtr >= src.size())
        {
            finish(selectArray, selectLen);
        }
        else
        {
            doit(src, lookupPtr+1, selectLen, selectArray, finish);
            selectArray[selectLen] = src[lookupPtr];
            doit(src,lookupPtr+1, selectLen+1, selectArray, finish);
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        int * selectArray = new int[S.size()];
        sort(S.begin(), S.end());
        vector<vector<int> > tmp;
        doit(S, 0, 0, selectArray, [&tmp](int* sa, int sl){
            vector<int> tmp2(sl);
            for (int i=0; i<sl; i++)
            {
                tmp2[i] = sa[i];
            }
            tmp.push_back(std::move(tmp2));
        });
        return tmp;
    }
};

void printVV(vector<vector<int> > s)
{
    for (auto i : s)
    {
        printf("[");
        for(auto j : i)
        {
            printf("%d ", j);
        }
        printf("]\n");
    }
}

int main()
{
    Solution s;
    vector<int> t1 = {4,2,3};
    printVV(s.subsets(t1));
    return 0;
}