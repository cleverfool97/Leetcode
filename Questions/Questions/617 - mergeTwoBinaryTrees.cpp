#include "617 - mergeTwoBinaryTrees.h"

/*
Difficulty: Easy
Please refer to "617. Merge Two Binary Trees" for the problem statement.
https://leetcode.com/problems/merge-two-binary-trees/description/

Solution:
    We perform a traversal through both trees. If both exist then we just merge them as specified.
    Otherwise, if only one exists then we just add that one node in the right spot and continue onwards left and right.
    The key is to realize that since each call is returning the new node, we have the call also set its left and rights to the return value of the call to the left and right subtree.
    By doing so, we can construct the tree recursively.

    Let M be the number of nodes in t1, and N be the number of nodes in t2
    Time Complexity: O(M + N). Only root overlaps.
    Space Complexity: TODO

Be Aware:
    -Is there a way to do this iteratively?

Tests:
    Trees with total overlap
    Trees with minimal overlap
    Trees where one is a subtree of the other
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

TreeNode* Solution617::mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if (t1 == nullptr && t2 == nullptr) return nullptr;
    if (t1 != nullptr && t2 != nullptr)
    {
        TreeNode* toAdd = new TreeNode(t1->val + t2->val);
        toAdd->left = mergeTrees(t1->left, t2->left);
        toAdd->right = mergeTrees(t1->right, t2->right);
        return toAdd;
    }
    else if (t1 != nullptr)
    {
        TreeNode* toAdd = new TreeNode(t1->val);
        toAdd->left = mergeTrees(t1->left, nullptr);
        toAdd->right = mergeTrees(t1->right, nullptr);
        return toAdd;
    }
    else
    {
        TreeNode* toAdd = new TreeNode(t2->val);
        toAdd->left = mergeTrees(nullptr, t2->left);
        toAdd->right = mergeTrees(nullptr, t2->right);
        return toAdd;
    }
}