#ifndef LEET112_H
#define LEET112_H



struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution112
{
public:
    bool hasPathSum(TreeNode* root, int sum);
    bool hasPathSumHelper(TreeNode* root, int sum, int current);
};
#endif
