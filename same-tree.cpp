/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool mxor(bool a, bool b)
{
    return (a&&!b)||(!a&&b);
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (mxor(p==nullptr, q==nullptr))
        return false;
        if (p==nullptr)
            return true;

        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};

int main()
{
    return 0;
}