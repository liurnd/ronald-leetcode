//
// Created by Ronald Liu on 18/5/15.
//
#include "leetcode_tree.h"

TreeNode *getfull3Tree()
{
    TreeNode *tmp = new TreeNode(0);

    tmp->left = new TreeNode(1);
    tmp->right = new TreeNode(2);

    tmp->left->left = new TreeNode(3);
    tmp->left->right = new TreeNode(4);
    tmp->right->left = new TreeNode(4);
    tmp->right->right = new TreeNode(5);

    return tmp;
}