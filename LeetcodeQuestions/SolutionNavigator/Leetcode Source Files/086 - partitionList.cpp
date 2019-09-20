#include "086 - partitionList.h"
#include "config.h"

/*
Difficulty: Medium
Please refer to "86. Partition List" for the problem statement.
https://leetcode.com/problems/partition-list/description/

Solution:
    Simply have two linked lists, one representing the early half and one representing the later half, and iterate once through the linked list and assign each node in order.
    Then, it's simply a matter of attaching one half to another to get the solution.
    
    Let N be the number of nodes in the linked list
    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware: 
    -Note the use of sentinel nodes to make pointer management and special case considerations a little easier than before.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

ListNode* Solution086::partition(ListNode* head, int x)
{
    ListNode *leftPartSentinel = new ListNode(0);
    ListNode *rightPartSentinel = new ListNode(0);
    ListNode *leftCounter = leftPartSentinel;
    ListNode *rightCounter = rightPartSentinel;

    while (head != nullptr)
    {
        if (head->val < x)
        {
            leftCounter->next = head;
            leftCounter = leftCounter->next;
        }
        else
        {
            rightCounter->next = head;
            rightCounter = rightCounter->next;
        }
        head = head->next;
    }
    rightCounter->next = nullptr;
    leftCounter->next = rightPartSentinel->next;

    return leftPartSentinel->next;
}
