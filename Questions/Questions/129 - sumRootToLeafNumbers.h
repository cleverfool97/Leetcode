#ifndef LEET129_H
#define LEET129_H


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution129
{
public:
    int sumNumbers(TreeNode* root);

    int sumNumbersHelper(TreeNode* root, int path);
};

#endif
