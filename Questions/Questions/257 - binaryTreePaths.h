#ifndef LEET257_H
#define LEET257_H

#include "config.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution257
{
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root);
    void binaryTreePathsHelper(TreeNode* root, std::string curPath, std::vector<std::string>& result);
};
#endif
