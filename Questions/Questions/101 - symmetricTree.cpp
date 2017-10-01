#include "101 - symmetricTree.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "101. Symmetric Tree" for the problem statement.

Solution: 
    We simply take note of the fact that if we begin at the root and split down the middle, after the root's children
    the successive left nodes should match the opposite side's right nodes.
    If at any point there is a null pointer discrepancy then the tree is asymmetrical by structure.
    Otherwise we check the values of competing nodes and then pass the algorithm down, until we reach a pair of nullpointers.
    This is a classic recursive solution.

    Let N be the total number of nodes in the tree.
    Time Complexity: O(N), each node must be visited to prove symmetry
    Space Complexity: O(1), unless considering recursive call stack, in which case O(N).

Be Aware:
    -Make sure you nail down your base cases!
    -When dealing with these problems, if the original function signature doesn't seem to be enough, write a helper!
    -Space complexity calculations can be tricky with recursive calls because of the way functions work on the call stack. Look up tail recursion to see ways to address this!
    -Can this function be optimized to be tail recursive?

Tests:
    -Empty tree
    -Tree with just a root
    -Symmetric tree with a root and two children
    -Asymmetric tree with a root and two children
    -Asymmetric tree by structure
    -Asymmetric tree by value
    -Large symmetric tree for robustness.
    -Large tree with only one imperfection
*/

bool Solution101::isSymmetric(TreeNode* root)
{
    if (root == nullptr) return true;
    return isSymmetricHelper(root->left, root->right);
}

bool Solution101::isSymmetricHelper(TreeNode* r1, TreeNode* r2)
{
    if (r1 == nullptr && r2 == nullptr) return true;
    if (r1 == nullptr || r2 == nullptr) return false;

    if (r1->val != r2->val) return false;
    return isSymmetricHelper(r1->left, r2->right) && isSymmetricHelper(r1->right, r2->left);
}