//
// Created by Ronald Liu on 1/6/15.
//
#include <stack>
#include <vector>
#include "leetcode_tree.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> tmp;
        if (root==nullptr)
            return tmp;
        stack<pair<int, TreeNode*> > runStack;
        runStack.emplace(0, root);
        while(!runStack.empty())
        {
            auto& a = runStack.top();
            switch(a.first)
            {
            case 0:
                if (a.second->left)
                {
                    a.first = 1;
                    runStack.emplace(0, a.second->left);
                    continue;
                }
            case 1:
                if (a.second->right)
                {
                    a.first = 2;
                    runStack.emplace(0, a.second->right);
                    continue;
                }
            case 2:
                tmp.push_back(a.second->val);
                runStack.pop();
            }
        }
        return tmp;
    }
};

#include <iostream>
int main()
{
    Solution s;
    for (auto i : s.postorderTraversal(getfull3Tree()))
    {
        cout << i << endl;
    }
    return 0;
}