#include "144 - binaryTreePreorderTraversal.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "144. Binary Tree Preorder Traversal" for the problem statement.
https://leetcode.com/problems/binary-tree-preorder-traversal/description/

Solution:
    To perform a preorder traversal iteratively, we use a stack, that only contains non-nullptr TreeNode pointers.
    If the root is pointing at an actual TreeNode, we add it to the stack.
    Then, so long as the stack isn't empty, we take the value stored in the node at the top of the stack and append it to our result.
    Then, we pop the processed node up, then push its right child if it is not nullptr, then its left child if it is not nullptr.
    This ensures that we will process a node, then its left child, then its right child, just like in a preorder traversal.

    Let N be the number of nodes in the tree.
    Time Complexity: O(N), a traversal
    Space Complexity: O(N), the stack will contain N/2 nodes at some point for a full, complete binary tree.

Be Aware:
    -How might this solution be adapted to use 
    -What would be a recursive method of doing this? How about the space complexity of that?

Tests:
    Empty tree
    Tree with one node
    Full, complete tree with depth 5
    Tree with many branches that terminate at different depths
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

vector<int> Solution144::preorderTraversal(TreeNode* root)
{
    if (root == nullptr) return vector<int>();

    vector<int> result;

    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode* temp = stk.top();
        result.push_back(temp->val);
        stk.pop();
        if (temp->right != nullptr) stk.push(temp->right);
        if (temp->left != nullptr) stk.push(temp->left);
    }

    return result;
}