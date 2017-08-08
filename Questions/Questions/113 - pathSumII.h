#ifndef LEET113_H
#define LEET113_H

#include "config.h"
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode
{   
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution113
{
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum);
    void pathSumHelper(TreeNode* root, int sum, std::vector<int>& path, std::vector<std::vector<int>>& result);
};

#endif