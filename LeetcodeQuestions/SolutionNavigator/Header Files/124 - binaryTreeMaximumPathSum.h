#ifndef LEET124_H
#define LEET124_H

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution124
{
public:
    int maxPathSum(TreeNode* root);
    int maxPathSumHelper(TreeNode* root, int& result);
};
#endif