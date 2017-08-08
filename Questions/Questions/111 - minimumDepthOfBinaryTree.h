#ifndef LEET111_H
#define LEET111_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution111
{
public:
    int minDepth(TreeNode* root);
    int minDepthHelper(TreeNode* root);
};
#endif