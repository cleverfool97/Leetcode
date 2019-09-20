#include "235 - lowestCommonAncestorOfABinarySearchTree.h"

/*
Difficulty: Easy
Please refer to "235. Lowest Common Ancestor of a Binary Search Tree" for the problem statement.
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

Solution:
    In a binary search tree, for every node, we know that the value it stores is larger than the values stored in the left subtree, and smaller than the values of the right subtree (generally for equal values they are to the right, or simply not allowed).
    In order for a node to be the lowest common ancestor of two other nodes, the two nodes must be on opposite ends of the tree.
    Otherwise, we can continue down in the direction that they are both in to get a lower common ancestor!

    Let N be the number of nodes in the tree
    Time Complexity: O(N), consider a long tree with 1 leaf and every parent only having a right node. q is the leaf, p is the parent.
    Space Complexity: O(1), this is tail recursive! For any given path, we are only moving the node we are considering without needing to wait for additional calculations!

Tests:
    TODO
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

TreeNode* Solution235::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr) return nullptr;
    if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    return root;
}