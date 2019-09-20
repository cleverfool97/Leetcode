#include "257 - binaryTreePaths.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "257. Binary Tree Paths" for the problem statement.
https://leetcode.com/problems/binary-tree-paths/description/

Solution:
    Use a helper recursive function that tracks the string representing the current path and adds to that as it goes down.
    The helper should also keep a reference to the vector of strings that will be our result.

    Whenever we encounter a node that has no children, it is a leaf so we append its value to the path and append that path to the result!

    Let N represent the number of nodes in the tree
    Time Complexity: O(N), each node visited once and some constant operations are applied
    Space Complexity: O(N), every node will be a part of one of the paths in the result. Also, consider the call stack for recursive calls.

Be Aware:
    -We pass in a reference to the result data structure so that each call is considering the same one. This also saves a lot of space on the call stack (we'd otherwise have lots of duplicates during runtime!)

Tests:
    Empty tree
    Tree with one node
    Full, complete tree with depth 3
    Tree with branches ending at various depths up to depth 5
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

vector<string> Solution257::binaryTreePaths(TreeNode* root)
{
    vector<string> result;
    if (root == nullptr) return vector<string>();
    binaryTreePathsHelper(root, "", result);
    return result;
}

void Solution257::binaryTreePathsHelper(TreeNode* root, string curPath, vector<string>& result)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (curPath == "") result.push_back(to_string(root->val));
        else result.push_back(curPath + "->" + to_string(root->val));
    }

    if (curPath != "") curPath += "->";
    binaryTreePathsHelper(root->left, curPath + to_string(root->val), result);
    binaryTreePathsHelper(root->right, curPath + to_string(root->val), result);
}