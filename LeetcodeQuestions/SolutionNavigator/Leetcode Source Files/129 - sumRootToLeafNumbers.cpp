#include "129 - sumRootToLeafNumbers.h"

/*
Difficulty: Medium
Please refer to "129. Sum Root to Leaf Numbers" for the problem statement.
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

Solution:
    We simply write a helper function that allows us to track the running tally down each path. As soon as we encounter a leaf node, we can return that value as a path sum.
    Otherwise, we take the node's current value, account for it as part of our running number, and return the sum down both the left and right.
    
    Let N be the number of nodes in the tree
    Time Complexity: O(N)
    Space Complexity: O(N)

Tests:
    Empty Tree
    Tree with just a root
    Full and complete tree
    Tree with branches ending at many depths

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

int Solution129::sumNumbers(TreeNode* root)
{
    return sumNumbersHelper(root, 0);
}

int Solution129::sumNumbersHelper(TreeNode* root, int path)
{
    if (root == nullptr) return 0;
    int new_path = path * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) return new_path;
    return sumNumbersHelper(root->left, new_path) + sumNumbersHelper(root->right, new_path);
}