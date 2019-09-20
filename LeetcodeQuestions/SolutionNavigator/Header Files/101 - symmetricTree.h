#ifndef LEET101_H
#define LEET101_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution101 
{
public:
    bool isSymmetric(TreeNode* root);
    bool isSymmetricHelper(TreeNode* r1, TreeNode* r2);
};
#endif
