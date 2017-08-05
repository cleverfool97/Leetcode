#include "100 - sameTree.h"
#include "config.h"

/*
Please refer to "100. Same Tree" for the problem statement.

Solution:
    If both pointers are nullptr, then it is true as a base case.
    After this check if either of them are, then it must be false by structure.
    Otherwise just check the current pair's value, as well as if these properties hold true for the left and right subtrees.

Tests:
    -Empty tree
    -Single node same tree
    -Single node different tree
    -Tree different by structure
    -Tree different by only value
    -Tree different by both
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
bool Solution100::isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}