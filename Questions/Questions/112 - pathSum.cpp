#include "112 - pathSum.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "112. Path Sum" for the problem statement.

Solution:
    While we traverse the tree, we keep track of a running total in each direction that we go in.
    Whenever we reach a root node we see if the running total matches the sum.

    Let N be the number of nodes in the tree.
    Time Complexity: O(N), the final leaf that we consider might contain the path that represents the sum, even though all the others have failed.
    Space Complexity: O(N), consider the call stack

Be Aware:
    -Watch out for your base cases.
    -This is another good example of how using a helper recursive function can make it a lot easier to solve.

Tests:
    -Empty tree
    -Tree with no path sum
    -Tree with a path sum
    -Tree with root value 1, left value 2, and sum 1. This should return false, but if base case coded wrong could return true.
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

bool Solution112::hasPathSum(TreeNode* root, int sum)
{
    if (root == nullptr) return false;
    return hasPathSumHelper(root, sum, 0);
}

bool Solution112::hasPathSumHelper(TreeNode* root, int sum, int current)
{
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr) return sum == current + root->val;

    return hasPathSumHelper(root->left, sum, current + root->val) || hasPathSumHelper(root->right, sum, current + root->val);
}