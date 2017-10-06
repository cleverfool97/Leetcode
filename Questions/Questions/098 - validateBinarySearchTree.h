#ifndef LEET098_H
#define LEET098_H

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution098
{
public:
    bool isValidBST(TreeNode* root);
    bool validate(TreeNode* root, TreeNode* &prev);
};
#endif
