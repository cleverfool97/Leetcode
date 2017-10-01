#include "100 - sameTree.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "100. Same Tree" for the problem statement.

Solution:
    If both pointers are nullptr, then it is true as a base case.
    After this check if either of them are, then it must be false by structure.
    Otherwise just check the current pair's value, as well as if these properties hold true for the left and right subtrees.

    Let M be the number of nodes in tree p, and N be the number of nodes in tree q
    Time Complexity: O(min(M, N)), if one tree is smaller then worst case we find out they aren't the same tree after all of the nodes in the smaller tree have been tested
    Space Complexity: O(1), unless counting space on call stack for recursive call, then O(min(M, N)), if input is two binary trees that are the same except for the leaf, and each non-leaf has only 1 child node.

Be Aware:
    Recursive calls need to store information on the call stack. That is, if a call to a recursive function hasn't returned yet, it needs to store information until it does.
    What this means is that if a recursive call goes many levels deep and is not tail recursive, then the space on the call stack will pile up.

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