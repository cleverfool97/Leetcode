#include "021 - mergeTwoSortedLists.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "21. Merge Two Sorted Lists" for the problem statement.

Solution:
    Fairly straightforward. So long as there exists a node in either list to merge, select the appropriate node and assign it to a ListNode pointer's next.

    Let N be the total number of nodes, that is the sum of the lengths of l1 and l2
    Time Complexity: O(N), each node is visited once when merging
    Space Complexity: O(1), just one sentinel node per function call, and a pointer

Be Aware:
    -Uses the sentinel node strategy to eliminate need for some edge cases.
    -Assumes sorting in increasing order.

Tests:
    l1: []
    l2: []

    l1: [1]
    l2: []

    l1: [1,2,3,4,5]
    l2: [1,3,5,7,9]

    l1: [1,3,5,7,9]
    l2: [2,4,6,8]
*/
ListNode* Solution021::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *sentinel = new ListNode(0);
    ListNode *temp = sentinel;

    while (l1 != nullptr || l2 != nullptr)
    {
        if (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
        }
        else if (l1 != nullptr)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }

        temp = temp->next;
    }

    return sentinel->next;
}