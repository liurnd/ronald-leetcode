//
// Created by Ronald Liu on 14/5/15.
//
#include <vector>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        travel(0, root, result);
        return result;
    }
    void travel(int level, TreeNode* root, vector<int>& result) {
        if (root == nullptr)
            return;
        if (level >= result.size())
        {
            result.push_back(root->val);
        }
        else
            result[level] = root->val;
        if (root->left)
            travel(level+1, root->left, result);
        if (root->right)
            travel(level+1, root->right, result);
    }
};