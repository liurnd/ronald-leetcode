//
// Created by Ronald Liu on 30/4/15.
//

#include <deque>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void doIt(TreeNode* root, vector<int>& res)
    {
        std::deque<std::pair<TreeNode*, int> > stack;
        auto next = root;
        while(true)
        {
            if (next->left)
            {
                stack.push_front(std::make_pair(next, 0));
                next = next->left;
            }
            else if (next->right)
            {

            }
        }
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> tmp;
        if (root)
            doIt(root, tmp);
        return tmp;
    }
};

int main()
{
    TreeNode a(0);
    TreeNode a1(1);
    TreeNode a2(2);
    a1.left =&a;
    a1.right = &a2;
    Solution s;
    auto res = s.preorderTraversal(&a1);
    for (auto i : res)
        cout << i << " ";
    return 0;
}
