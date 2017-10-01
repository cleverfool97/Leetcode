#include "114 - flattenBinaryTreeToLinkedList.h"
#include "config.h"

/*
Difficulty: Medium
Please refer to "114. Flatten Binary Tree to Linked List" for the problem statement.

Solution:
    This problem can be solved iteratively.
    Initialize temp at the root.
    While temp isn't nullptr
        If it's left isn't a nullptr
            Save temp's current right so we don't lose it
            Move temp's left to temp's right.
            Proceed as far right as we can
            Reattach the saved right to the rightmost portion.
        Move temp to its right

    Let N be the number of nodes in the tree.
    Time Complexity: N/A (TODO)
    Space Complexity: O(1), iterative solution with only a few pointers initialized
Be Aware:
    -Notice that in the problem the final form corresponds to a preorder traversal. So in essence this iterative solution is a preorder traversal + manipulations.
    -Every time a node has a left, we want that node to end up as the immediate right. This propagates recursively (so a recursive solution is quite easy here)
    -However, by our implementation the next node we consider by moving right is identically the one that we just considered in our preorder traversal, which is why it works.
    -rightHolder holds the right half of a subtree. It's added at the end because we know that in a preorder traversal all of the left items will be considered first.
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

void Solution114::flatten(TreeNode* root)
{
    if (root == nullptr) return;
    TreeNode *temp = root;
    while (temp != nullptr)
    {
        if (temp->left != nullptr)
        {
            TreeNode *rightHolder = temp->right;
            temp->right = temp->left;
            temp->left = nullptr;

            TreeNode *rightDiver = temp;
            while (rightDiver->right != nullptr)
                rightDiver = rightDiver->right;
            rightDiver->right = rightHolder;
        }
        temp = temp->right;
    }
}