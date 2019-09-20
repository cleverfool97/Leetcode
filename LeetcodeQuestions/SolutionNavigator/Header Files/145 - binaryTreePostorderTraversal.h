#ifndef LEET145_H
#define LEET145_H

#include "config.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution145
{
public:
    std::vector<int> postorderTraversal(TreeNode* root);
};
#endif
