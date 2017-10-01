#include "141 - linkedListCycle.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "141. Linked List Cycle" for the problem statement.
https://leetcode.com/problems/linked-list-cycle/description/

Solution:
    We have a slow "tortoise" pointer that jumps one at a time.
    We also have a fast "hare" pointer that jumps two at a time.
    After they both jump away from the start, if there is a cycle the hare will catch the tortoise.
    Otherwise the hare will eventually reach the end and there will be no cycle.

Be Aware:
    -Watch out for null pointer access, especially with the hare.
    -Don't accidentally check to see if they're the same spot at the start and have that be the cycle.
Test Cases:
    -Empty list
    -List with no cycle
    -List with a cycle of 3, with the 2nd node as the entry point.
    -List with a cycle of 4, with the 2nd node as the entry point.
    -List with a cycle of 5, with the 2nd node as the entry point.
    -List with a cycle of 3, with the 3rd node as the entry point.
    -List with a cycle of 4, with the 3rd node as the entry point.
    -List with a cycle of 5, with the 3rd node as the entry point.
    -List with a node that points back to itself as a cycle.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

bool Solution141::hasCycle(ListNode *head)
{
    ListNode *tortoise = head;
    ListNode *hare = head;

    while (hare != nullptr)
    {
        tortoise = tortoise->next;
        hare = hare->next;
        if (hare == nullptr) return false;
        hare = hare->next;
        if (hare == tortoise) return true;
    }

    return false;
}
