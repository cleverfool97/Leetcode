#include "236 - lowestCommonAncestorOfABinaryTree.h"
#include "config.h"

/*
Difficulty: Medium
Please refer to "236. Lowest Common Ancestor of a Binary Tree" for the problem statement.
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Solution:
    We can glean no information from the values in the tree because it isn't a binary search tree or otherwise constrained.
    Instead, we use the pointers themselves. We return the root if it's nullpointer or either p or q.
    This means that if we perform a recursive call and the result is not nullptr, the subtree we called on contains either p or q, or both.

    With this implemented, the logic then looks like this:
        -If the root is nullptr, p, or q, return it
        -Set a pointer to the result of calling on the left subtree
        -Set a pointer to the result of calling on the right subtree
        -If left is nullptr, then it has neither p or q and we can go lower in ancestry by moving right (only considering the result of the right subtree's recursive call)
        -If right is nullptr, then the same logic applies and we can go lower in ancestry by moving left
        -If neither is nullptr, then the lowest ancestor has to be the root; going either way will lose either p or q
        -Note that there is no situation where both the result of the left and right calls are nullptr

    Let N be the number of nodes in the tree
    Time Complexity: O(N)
    Space Complexity: O(N), consider a tree with 1 leaf, q pointing to that leaf, and p as the parent. Each parent's child is the left pointer. The function will have N - 2 recursive calls on the stack.
*/

TreeNode* Solution236::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    return (left == nullptr) ? right : (right == nullptr) ? left : root;
}