#ifndef LEET617_H
#define LEET617_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution617
{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
};

#endif
