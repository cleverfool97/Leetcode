#include "002 - addTwoNumbers.h"
#include "config.h"

/*
Please refer to Leetcode's "2. Add Two Numbers" for the problem statement.

Solution:
    It is just a matter of keeping track of where you are at each linked list and performing additions on the digits, propagating a carry along (in case the sum of the digits exceeds 10).
    
Be Aware:
    -Make sure to account for the case of different length linked list inputs.
    -Remember to push back a ListNode that holds the carry at the end if it exists.
    -This code can be written with three while loops, with the first one as "while (l1 != nullptr && l2 != nullptr)". Why might this approach not be ideal?
    -having a sentinel node that points to the start of the actual solution is a strategy that in some cases allows you to avoid coding for special nullptr scenarios.

Tests:
    l1: 2 -> 4 -> 3
    l2: 5 -> 6 -> 4

    l1: 0
    l2: 0

    l1: 0
    l2: 1

    l1: 1
    l2: 9 -> 9 -> 9

    l1: 3 -> 4 -> 7
    l2: 2 -> 5 -> 1 -> 8
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* Solution002::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* sentinel = new ListNode(0);
    ListNode* iter = sentinel;
    int rval, carry = 0;

    while (l1 != nullptr || l2 != nullptr)
    {
        if (l1 != nullptr && l2 != nullptr)
            rval = l1->val + l2->val + carry;
        else if (l1 != nullptr)
            rval = l1->val + carry;
        else
            rval = l2->val + carry;

        carry = rval / 10;
        rval = rval % 10;

        iter->next = new ListNode(rval);
        iter = iter->next;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    if (carry) iter->next = new ListNode(carry);

    return sentinel->next;
}