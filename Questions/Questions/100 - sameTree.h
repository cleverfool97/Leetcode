#ifndef LEET100_H
#define LEET100_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution100
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q);
};
#endif
