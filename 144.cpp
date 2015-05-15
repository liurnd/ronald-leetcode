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
        std::deque<TreeNode*> stack;
		stack.push_front(root);
        while(!stack.empty())
        {
            TreeNode* node = stack.front();
            stack.pop_front();
            res.push_back(node->val);
            if (node->right)
                stack.push_front(node->right);
            if (node->left)
                stack.push_front(node->left);
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
