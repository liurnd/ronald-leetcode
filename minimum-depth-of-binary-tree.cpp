//
// Created by Ronald Liu on 18/5/15.
//

#include "leetcode_tree.h"

#include <deque>

class Solution {
public:
    std::deque<std::pair<TreeNode*, int> >queue;

    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue.emplace_back(root, 1);
        while (!queue.empty())
        {
            auto t = queue.front();
            auto nRoot = t.first;
            auto level = t.second;

            if (nRoot->left == nullptr && nRoot->right == nullptr)
                return level;

            queue.pop_front();
            if (nRoot->left)
                queue.emplace_back(nRoot->left, level+1);
            if (nRoot->right)
                queue.emplace_back(nRoot->right, level+1);
        }
        return 0;
    }
};

#include <iostream>
int main()
{
    auto tmp = getfull3Tree();
    Solution s;
    std::cout << s.minDepth(tmp) << std::endl;
    return 0;
}