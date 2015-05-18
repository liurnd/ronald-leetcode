//
// Created by Ronald Liu on 18/5/15.
//

#ifndef LEETCODE_LEETCODE_TREE_H
#define LEETCODE_LEETCODE_TREE_H

#include <stddef.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *getfull3Tree();


#endif //LEETCODE_LEETCODE_TREE_H
