//
// Created by Ronald Liu on 14/5/15.
//

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<int, int> num_parent;
    unordered_map<int, int> set_size;
public:
    int get_father(int id)
    {
        if (num_parent[id] != id)
            num_parent[id] =  get_father(num_parent[id]);
        return num_parent[id];
    }
    void merge(int id, int id2)
    {
        num_parent[get_father(id)] = get_father(id2);
    }
    bool is_consecutive(int id, int id2)
    {
        return get_father(id) == get_father(id2);
    }

    int longestConsecutive(vector<int>& nums) {
        for (auto i : nums)
        {
            if (num_parent.count(i) == 0)
            {
                num_parent[i] = i;
                if (num_parent.count(i-1)!=0)
                {
                    merge(i, i-1);
                }
                if (num_parent.count(i+1)!=0)
                {
                    merge(i, i+1);
                }
            }
        }

        int max = 0;
        for (auto i : num_parent)
        {
            int father = get_father(i.first);
            if (set_size.count(father)==0)
                set_size[father] = 1;
            else
                set_size[father]++;
            if (set_size[father]>max)
                max = set_size[father];
        }

        return max;
    }
};


int main()
{
    Solution s;
    vector<int> buf = {100,4,6,8,200,1,3,2,5};
    cout << s.longestConsecutive(buf) << endl;
    return 0;
}