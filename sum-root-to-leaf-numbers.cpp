//
// Created by Ronald Liu on 29/5/15.
//
#include "leetcode_tree.h"

#include <iostream>
using namespace std;
class Solution {
public:
    int iter(TreeNode* root, int nNum, int sum)
    {
        int nextLevel = (nNum+root->val)*10;
        if (root->left)
        {
            sum = iter(root->left, nextLevel, sum);
        }
        if (root->right)
        {
            sum = iter(root->right, nextLevel, sum);
        }
        if (!root->left && !root->right)
        {
            return sum + nNum+root->val;
        }
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        return iter(root, 0, 0);
    }
};

int main()
{
    Solution s;
    cout << s.sumNumbers(getfull3Tree()) << endl;
    return 0;
}
