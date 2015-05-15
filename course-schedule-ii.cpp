//
// Created by Ronald Liu on 14/5/15.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> next(numCourses);
        vector<int> inDeg(numCourses);
        for (auto i : prerequisites)
        {
            next[i.second].push_back(i.first);
            inDeg[i.first]++;
        }

        for (int ii=0; ii < numCourses; ii++)
        {
            bool hasNew = false;
            auto i = 0;
            for (;i<inDeg.size();i++)
            {
                if (inDeg[i] == 0)
                {
                    hasNew = true;
                    break;
                }
            }

            if (!hasNew)
            {
                return {};
            }
            inDeg[i] = -1;
            result.push_back(i);
            for (auto n : next[i])
            {
                inDeg[n]--;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> >ab = {{1,0},{2,0},{3,1},{3,2}};
    //vector<pair<int, int> >ab = {{1,0}};
    auto res = s.findOrder(4, ab);
    for (auto i : res)
    {
        cout<<i << " ";
    }
    cout << endl;
    return 0;
}