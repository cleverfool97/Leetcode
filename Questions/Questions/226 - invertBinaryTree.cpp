#include "226 - invertBinaryTree.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "226. Invert Binary Tree" for the problem statement.

Solution:
    The key is to observe how an inverted binary tree looks like and realize that you can achieve inversion by switching each node's left and right pointers
    Time Complexity: O(N), where N is the number of nodes in the tree.
Tests:
    Empty Tree
    Tree with one node
    Binary tree of depth 3
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


TreeNode* Solution226::invertTree(TreeNode* root)
{
    if (root == nullptr) return nullptr;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}