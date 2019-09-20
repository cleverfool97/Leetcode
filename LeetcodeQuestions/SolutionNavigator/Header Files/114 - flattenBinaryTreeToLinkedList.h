#ifndef LEET114_H
#define LEET114_H


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution114
{
public:
    void flatten(TreeNode* root);
};
#endif


