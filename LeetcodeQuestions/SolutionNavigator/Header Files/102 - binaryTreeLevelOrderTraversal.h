#ifndef LEET102_H
#define LEET102_H



#include "config.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution102
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root);
};
#endif
