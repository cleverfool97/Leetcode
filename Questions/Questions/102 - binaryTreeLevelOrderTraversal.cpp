#include "102 - binaryTreeLevelOrderTraversal.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "102. Binary Tree Level Order Traversal" for the problem statement.

Solution: 
    The key is to realize that in a standard level order traversal, you can use a queue to process the nodes in level order.
    We can utilize nullptr in the queue to signal level advancements.
        -Check the root for nullptr case
        -Push back a nullptr after the root pointer before diving into the for loop.
        -Don't add any left or right nodes if they are nullptr.

    Let N be the total number of nodes in the tree.
    Time Complexity: O(N), each node must be visited to be included in the traversal
    Space Complexity: O(N), complete binary tree with last row filled, right before processing of last level begins there will be N/2 nodes in the queue (each other node added 2 pointers while processing itself)

Alterate Solution:
    Alternatively, you can have two queues, and use the emptying of one queue to signal moving to the next level.
    It is in the comments below, and also passed LeetCode's check. You can see for yourself if you'd like.
    This solution eliminates using nullptr as a sentinel but has the downside of additional complexity and an extra data structure.

Be Aware:
    -Don't forget to pop your queue. front() doesn't take away the top item!
    -Why won't a stack work in this situation?

Tests:
    -Empty tree
    -Tree with one item.
    -Any tree with significantly complex branching.
    -A complete tree.
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

vector<vector<int>> Solution102::levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> q;

    if (root == nullptr) return result;
    q.push(root);
    q.push(nullptr);

    vector<int> level;
    while (!q.empty())
    {
        TreeNode* front = q.front();
        if (front != nullptr)
        {
            level.push_back(front->val);
            if (front->left != nullptr) q.push(front->left);
            if (front->right != nullptr) q.push(front->right);
        }
        else
        {
            result.push_back(level);
            level.clear();
            if (q.size() != 1) q.push(nullptr);
        }
        q.pop();
    }

    return result;
}

/*
Alternate Solution
vector<vector<int>> Solution102::levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;

    if (root == nullptr) return result;
    q1.push(root);

    vector<int> level;
    while (!q1.empty() || !q2.empty())
    {
        if (!q1.empty())
        {
            while (!q1.empty())
            {
                TreeNode* front = q1.front();
                if (front != nullptr)
                {
                    level.push_back(front->val);
                    if (front->left != nullptr) q2.push(front->left);
                    if (front->right != nullptr) q2.push(front->right);
                }
                q1.pop();
            }
        }
        else
        {
            while (!q2.empty())
            {
                TreeNode* front = q2.front();
                if (front != nullptr)
                {
                    level.push_back(front->val);
                    if (front->left != nullptr) q1.push(front->left);
                    if (front->right != nullptr) q1.push(front->right);
                }
                q2.pop();
            }
        }

        result.push_back(level);
        level.clear();
    }

    return result;
}
*/
