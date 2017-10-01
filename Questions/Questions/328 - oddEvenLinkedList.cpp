#include "328 - oddEvenLinkedList.h"

/*
Difficulty: Easy
Please refer to "328. Odd Even Linked List" for the problem statement.

Solution:
    Initialize two pointers, one to the head to represent the beginning of the odd list, one to head's next if it exists to represent the beginning of the even list.
    Treat the linked list as two separate linked lists woven together, and reassign pointers such that all the evens are in one linked list and the odds in the other.
    After that is complete, it's just a matter of pointing the last element in the odd linked list to the head of the even linked list.

    Let N be the number of nodes in the input linked list.
    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware: 
    -Make sure you keep track of where all of your pointers are.

Tests:
    Empty list
    1
    1->2
    1->2->3
    1->2->3->4
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

ListNode* Solution328::oddEvenList(ListNode* head)
{
    if (head == nullptr) return nullptr;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_head = even;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_head;

    return head;
}