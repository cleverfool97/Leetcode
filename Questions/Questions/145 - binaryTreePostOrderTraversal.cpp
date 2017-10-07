#include "145 - binaryTreePostorderTraversal.h"
#include "config.h"

using namespace std;

/*
Difficulty: Hard
Please refer to "145. Binary Tree Postorder Traversal" for the problem statement.
https://leetcode.com/problems/binary-tree-postorder-traversal/description/

Solution:
    We initialize a stack, and push the root onto it if it isn't nullptr.
    Then we continue to take the top item of the stack, push left if not nullptr, and push right if not nullptr, and adding the top item to the result.
    At the end, we reverse the entire result to change it from a preorder traversal to a postorder traversal.

    Essentially, before reversal we have:
        Process current
        Process right
        Process left
    Which becomes...
        Process left
        Process right
        Process current

    Let N be the number of nodes in the tree
    Time Complexity: O(N)
    Space Complexity: O(N)

Tests:
    Empty tree
    Full, complete tree of depth 5
    Sparse tree with branches that end at various depths
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

vector<int> Solution145::postorderTraversal(TreeNode* root)
{
    if (root == nullptr) return vector<int>();
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode* temp = stk.top();
        stk.pop();
        if (temp->left != nullptr) stk.push(temp->left);
        if (temp->right != nullptr) stk.push(temp->right);
        result.push_back(temp->val);
    }

    reverse(result.begin(), result.end());
    return result;
}