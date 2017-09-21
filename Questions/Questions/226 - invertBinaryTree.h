#ifndef LEET226_H
#define LEET226_H

#include "config.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution226
{
public:
    TreeNode* invertTree(TreeNode* root);
};

#endif