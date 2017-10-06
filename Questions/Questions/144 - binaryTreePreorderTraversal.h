#ifndef LEET144_H
#define LEET144_H

#include "config.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution144
{
public:
    std::vector<int> preorderTraversal(TreeNode* root);
};
#endif