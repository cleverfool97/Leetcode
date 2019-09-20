#include "104 - maximumDepthOfBinaryTree.h"

#include "config.h"
using namespace std;

/*
Difficulty: Easy
Please refer to "104. Maximum Depth of Binary Tree" for the problem statement.
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Solution:
    This solution takes a recursive approach to finding the result. 
        Base case: If the root is a null pointer, then it doesn't contribute to the height of the tree and we return 0.
        Recursive step: The root is not a null pointer, so it contributes to the maximum possible depth. We return that added to the maximum of either the maxDepth of the left subtree or the right subtree.

    Let N be the number of nodes in the binary tree.
    Time Complexity: O(N), every node must be visited because it can potentially contribute to the maximum depth.
    Space Complexity: O(1), unless accounting for recursive call stack, in which case O(N)

Be Aware:
    -As with all recursive problems, make sure that your recursive steps are reducing the problem closer to the base case. If not, your recursive solution may run forever!
    -As with all recursive problems, take note of whether your solution is tail recursive or not. If not then your recursive call might take space on the call stack!

Tests:
    Empty tree
    Complete binary tree of depth 2
    Complete binary tree of depth 2, except with an additional leaf that increases the depth to 3
    Tree with just a root node
    Tree with many branches that end at different depths
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

int Solution104::maxDepth(TreeNode* root)
{
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}