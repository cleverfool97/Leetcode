#include "237 - deleteNodeInALinkedList.h"

/*
Difficulty: Easy
Please refer to "237. Delete Node in a Linked List" for the problem statement.
https://leetcode.com/problems/delete-node-in-a-linked-list/description/

Solution:
    This is slightly less traditional in that normally you are given a predecessor to the node to be deleted.
    However, given the scenarios we will be using this function in, we can safely take the next node's value and place it in our current one, then delete the next node like normal.

    Time Complexity: O(1)
    Space Complexity: O(1)

Be Aware:
    -You can actually submit an answer that doesn't actually do any deletion and it will be accepted by LeetCode.
    -Make sure that in practice you call delete; otherwise that memory isn't really being freed for further usage.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

void Solution237::deleteNode(ListNode* node)
{
    node->val = node->next->val;
    ListNode *temp = node->next;
    node->next = node->next->next;
    delete temp;
}