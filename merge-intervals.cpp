//
// Created by Ronald Liu on 2/6/15.
//

#include <vector>
using namespace std;


struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
bool myfunction (const Interval& i, const Interval& j) { return i.start<j.start; }
#include <algorithm>
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myfunction);
        vector<Interval> res;
        if (intervals.size()==0)
            return res;
        int nb=intervals[0].start, ne = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start > ne)
            {
                res.emplace_back(nb, ne);
                nb = intervals[i].start;
                ne = intervals[i].end;
            }
            else
                ne = max(ne, intervals[i].end);
        }
        res.emplace_back(nb, ne);
        return res;
    }
};

#include <iostream>
int main()
{
    vector<Interval> t = {{1,3},{2,6},{8,10},{15,18}};

    Solution s;
    for (auto i : s.merge(t))
        cout << i.start << " " << i.end << endl;

    return 0;
}