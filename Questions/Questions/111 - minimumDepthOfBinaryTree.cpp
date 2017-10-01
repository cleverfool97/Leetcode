#include "111 - minimumDepthOfBinaryTree.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "111 - Minimum Depth of Binary Tree" for the problem statement.

Solution:
    Check at the beginning to see if we were handed an empty tree.
    If not, then we call the helper.
    The helper checks to see if we are at a leaf. If so, return 1.
    Otherwise, depending on what children we have we perform a 1 + minDepthHelper call on each child.
    
    Let N be the number of nodes in the tree
    Time Complexity: O(N), consider a tree with 1 leaf, and every other node has one child. Every node will be visited to find this leaf.
    Space Complexity: O(1), unless considering recursive call stack, in which case O(N).

Be Aware:
    -Be careful, remember that a node with any child is NOT a leaf node. How might this affect the way you write your base cases?
    -Can this be done more concisely?
    -This is a good example of how using a helper function makes things easier.
    -Can this function be made tail recursive? Why or why not?

    Tests:
    -Empty tree
    -Tree with one item.
    -Long snaking tree that is basically a linked list.
    -Big tree with leaves at varying depths.
    -Completely balanced binary tree.
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

int Solution111::minDepth(TreeNode* root)
{
    if (root == nullptr) return 0;
    return minDepthHelper(root);
}

int Solution111::minDepthHelper(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) return 1 + minDepthHelper(root->right);
    if (root->right == nullptr) return 1 + minDepthHelper(root->left);
    return 1 + min(minDepthHelper(root->left), minDepthHelper(root->right));
}