#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		if (root == nullptr)
			return 0;
		auto mTreeNode = buildMTree(root);
		return getMaxValue(mTreeNode->val, mTreeNode, root);
	}

	TreeNode* buildMTree(TreeNode* root)
	{
		if (root == nullptr)
			return nullptr;
		TreeNode* newRoot = new TreeNode(root->val);
		if (root->left)
		{
			auto lRoot = buildMTree(root->left);
			if (lRoot->val + root->val > newRoot->val)
				newRoot->val = lRoot->val + root->val;
			newRoot->left = lRoot;
		}
		if (root->right)
		{
			auto lRoot = buildMTree(root->right);
			if (lRoot->val + root->val > newRoot->val)
				newRoot->val = lRoot->val + root->val;
			newRoot->right = lRoot;
		}
		return newRoot;
	}

	int getMaxValue(int nMax, TreeNode* mRoot, TreeNode* root)
	{
		nMax = max(nMax, mRoot->val);
		auto pLeft = mRoot->left ? mRoot->left->val : 0;
		auto pRight = mRoot->right ? mRoot->right->val : 0;
		
		nMax = max(nMax, pLeft + root->val);
		nMax = max(nMax, pRight + root->val);
		nMax = max(nMax, pRight + pLeft + root->val);
		if (mRoot->left)
		{
			nMax = getMaxValue(nMax, mRoot->left, root->left);
		}
		if (mRoot->right)
		{
			nMax = getMaxValue(nMax, mRoot->right, root->right);
		}
		return nMax;
	}
};

#include <iostream>
int main()
{
	Solution s;
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(-3);
	d.left = &a;
	d.right = &b;
	b.left = &c;
	cout << s.maxPathSum(&d) << endl;
	return 0;
}