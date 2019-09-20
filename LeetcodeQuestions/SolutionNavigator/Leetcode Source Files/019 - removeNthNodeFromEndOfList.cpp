#include "019 - removeNthNodeFromEndOfList.h"
#include "config.h"

/*
Difficulty: Medium
Please refer to "19. Remove Nth Node From End of List" for the problem statement
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Solution:
    In order to find the nth node from the end, we have a scout node go ahead by the input distance.
    Then we can slide both the scout and another node continue forwards until the scout hits a nullptr, at which we will have found the node to remove.

    Let M be the length of the input linked list.
    Time Complexity: O(M), iteration to the end of linked list, then constant time deletion
    Space Complexity: O(1), just one sentinel node, three pointers, and an integer

Be Aware:
    -Consider the case where the node to delete must be the first node.
    -Note that we haven't actually freed the memory associated with the node that we are removing.

Tests:
    -Linked list of size 1
    -Linked list of size > 1
    -Linked list of size > 1 with the node to delete to be the first node
*/

ListNode* Solution019::removeNthFromEnd(ListNode* head, int n)
{
    ListNode *sentinel = new ListNode(0);
    sentinel->next = head;
    ListNode *prev = sentinel;
    ListNode *scout = head;
    int counter = 0;

    while (counter < n)
    {
        scout = scout->next;
        counter++;
    }

    while (scout != nullptr)
    {
        prev = prev->next;
        scout = scout->next;
    }

    if (prev == sentinel) return head->next;
    if (prev->next != nullptr) prev->next = prev->next->next;
    return head;
}