#include "124 - binaryTreeMaximumPathSum.h"
#include "config.h"

using namespace std;

/*
Difficulty: Hard
Please refer to "124. Binary Tree Maximum Path Sum" for the problem statement.
https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

Solution:
    This problem is difficult because it is a recursion problem where there is a ton of stuff to keep track of.
    For every node, we are interested in the maximum path within its tree that includes itself, going in only one direction.
        By returning this information, we can use it recursively to construct longer paths.
    We also want to keep track of the value of the maximum path itself
        By having this tracked by reference and used in a helper function, we free up the return value to return the information above.
    
    Given a root node, there are a variety of paths can constitute the maximum path.
        1. The root node itself, with nothing else.
        2. The root node as one end of the path, with the path extending into the right subtree.
        3. The root node as one end of the path, with the path extending into the left subtree.
        4. The root node is in the middle of the path; that is, both the left and right nodes are included in the max path.
        5. The max path doesn't include this root, and is instead in the left subtree.
        6. The max path doesn't include this root, and is instead in the right subtree.

    How do we account for all of these situations with just the things we are tracking above?

    For a node, if we call the helper on the left and right subtrees, we get the maximum path sums that include the left and right nodes respectively.
    If either of them are negative, then we don't want to include those in the maximum path sum of the node we are currently considering.

    This covers scenarios 1-4:
        1. Both the left recursive call and the right recursive call produced negative values so including either would worsen our sum.
        2. The right recursive call produced a negative value, but the left recursive call produced a positive one, so it could potentailly contribute to our sum.
        3. The left recursive call produced a negatve value, but right recursive call produced a positive one, so it could potentially contribute to our sum.
        4. Both the left recursive call and the right recursive calls produced positive values that could potentially contribute to our sum.

    How about 5-6? This is why building upwards is important. As we go up, we keep track of the largest sum compared so far.
    For any given recursive call C, if 1-4 doesn't beat the stored result, then the 1-4 of a recursive call originating from call C produced a better value.
    In fact, we find that situations 5-6 are just a fancy way of saying, some later call's 1-4 stored a larger result here than the best solution that this call's 1-4 could produce.

    How does this all translate to code?
        Our original function initializes the running max to INT_MIN and triggers the helper call that has the reference to the max, returning it after the helper call completes.
        The helper does the meat of the work:
            If nullptr then return 0: it contributes nothing to the sum
            Store the results of the helper call on the left and right subtrees, setting them to 0 if they are less than 0 to represent not using that max sum
            If the current val + max including left node + max including right node > current max, then we update the max. This statement covers the best of situations 1-4.
            Return the current val + max(max including left node, max including right node), which is the max including the current root

        Let N be the number of nodes in the tree
        Time Complexity: O(N), every node is visisted once, and gets its current value + max including left + max including right calculated once
        Space Complexity: O(N), on the recursive call stack

Be Aware:
    -Note that this solution is very similar to Leetcode user xt2357's solution given at the following link: https://discuss.leetcode.com/topic/5508/simple-o-n-algorithm-with-one-traversal-through-the-tree
    -A key difference, is that his solution actually modifies the values of the nodes in the tree while the one I implemented does not perform this modification. Credit to him for the core of the algorithm; the solution here presents only a small improvement.
    -Note the usage of a reference to an integer to maintain a running result in the helper function, allowing the helper to return additional helpful information.
    -This is a bottom up recursive approach.
    -There are many path possibilities which makes it hard to account for each scenario individually.

Tests:
    TODO:
    Ideally it would be a full, complete tree with all nodes on the last row of depth 3, one test per configuration
    Also, a tree with only negative values would be nice to test as an edge case.
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

int Solution124::maxPathSum(TreeNode* root)
{
    int max = INT_MIN;
    maxPathSumHelper(root, max);
    return max;
}

int Solution124::maxPathSumHelper(TreeNode* root, int& result)
{
    if (root == nullptr) return 0;
    int left = maxPathSumHelper(root->left, result);
    int right = maxPathSumHelper(root->right, result);
    if (left < 0) left = 0;
    if (right < 0) right = 0;
    if (result < root->val + left + right) result = root->val + left + right;
    return root->val + max(left, right);
}