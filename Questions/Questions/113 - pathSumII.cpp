#include "113 - pathSumII.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "113. Path Sum II" for the problem statement.

Solution:
    We keep an integer vector representing a single path that we are constructing.
    We also pass in a reference to a vector of int vectors that will be our result.
    If we ever reach a leaf node and determine that the leaf is the end of a proper path, we add it to the result.

Be Aware:
    -Why is it better to pass the vectors in by reference rather than by value?
    -This is a good example of how using a helper function in a recursive call can help make the problem a lot easier.
    -Don't forget to pop out the back item on your path. Otherwise you might be keeping track of an incorrect path!

Tests:
    [5,4,8,11,null,13,4,7,2,null,null,5,1]
    22

    Empty tree

    [1, 2] 
    1

    [1, 2] 
    3

    []
    0
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
vector<vector<int>> Solution113::pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> result;
    vector<int> path;
    if (root == nullptr) return result;
    pathSumHelper(root, sum, path, result);
    return result;
}

void Solution113::pathSumHelper(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result)
{
    if (root == nullptr) return;
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr && root->val == sum)
        result.push_back(path);
    pathSumHelper(root->left, sum - root->val, path, result);
    pathSumHelper(root->right, sum - root->val, path, result);
    path.pop_back();
}