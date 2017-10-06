#include "098 - validateBinarySearchTree.h"

/*
Difficulty: Medium
Please refer to "98. Validate Binary Search Tree" for the problem statement.
https://leetcode.com/problems/validate-binary-search-tree/description/

Solution:
    A binary search tree will output its values in sorted order if we perform an inorder traversal.
    So, in order to validate it, we simply perform such a traversal, tracking the value stored in the previous node in the traversal, and returning false if at any point the order criteria fails.

    Let N be the number of nodes in the tree.
    Time Complexity: O(N), a traversal of the entire tree.
    Space Complexity: TODO

Be Aware:
    -Why does an inorder traversal produce the contents of a binary search tree in order (besides the name, of course).
    -What if the tree was just a binary tree, and not a binary search tree?

Tests:
    Empty Tree
    1 Node Tree
    Valid Tree
    Tree with all the same value
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

bool Solution098::isValidBST(TreeNode* root)
{
    TreeNode* prev = nullptr;
    return validate(root, prev);
}

bool Solution098::validate(TreeNode* root, TreeNode* &prev)
{
    if (root == nullptr) return true;
    if (!validate(root->left, prev)) return false;
    if (prev != nullptr && prev->val >= root->val) return false;
    prev = root;
    return validate(root->right, prev);
}
