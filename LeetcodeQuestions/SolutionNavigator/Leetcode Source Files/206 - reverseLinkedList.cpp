#include "206 - reverseLinkedList.h"

/*
Difficulty: Easy
Please refer to "206. Reverse Linked List" for the problem statement.
https://leetcode.com/problems/reverse-linked-list/description/

Solution:
    Initialize
        prev to nullptr
        cur to head
        next to cur->next (if cur is not nullptr)

    After every iteration of the loop, you want cur->next to become prev, and then move on to the original cur->next to repeat the same process.

    Let N be the number of nodes in the input linked list.
    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -This is a nice simple problem that is likely to appear as a short question on a data structures midterm.
    -Remember to check that a pointer is pointing to an existing object before trying to access any of that object's values.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

ListNode* Solution206::reverseList(ListNode* head)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *next;

    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}