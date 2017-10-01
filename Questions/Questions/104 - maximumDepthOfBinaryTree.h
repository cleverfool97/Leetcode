#ifndef LEET104_H
#define LEET104_H


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution104
{
public:
    int maxDepth(TreeNode* root);
};
#endif