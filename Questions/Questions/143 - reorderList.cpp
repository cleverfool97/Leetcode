#include "143 - reorderList.h"
#include "config.h"

/*
Please refer to "143. Reorder List" for the problem statement.

Solution:
    Iterate halfway through the list, reverse the second half, and then perform an alternating merge.

    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -Watch out for special cases.
    -Notice the use of a faster and slower moving pointer to find the halfway point of a linked list.
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
void Solution143::reorderList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) return;

    ListNode *tortoise = head;
    ListNode *hare = head;

    while (hare != nullptr)
    {
        tortoise = tortoise->next;
        hare = hare->next;
        if (hare != nullptr) hare = hare->next;
    }

    ListNode *temp = head;
    while (temp->next != tortoise) temp = temp->next;
    temp->next = nullptr;

    //Tortoise is now pointing at the start of the LL from which we want to reverse.
    ListNode *prev = nullptr;
    ListNode *next = tortoise->next;

    while (next != nullptr)
    {
        tortoise->next = prev;
        prev = tortoise;
        tortoise = next;
        next = tortoise->next;
    }
    tortoise->next = prev;

    //Prev now pointing at the start of the reversed LL
    ListNode *L1 = head;
    ListNode *L2 = tortoise;

    while (L1 != nullptr && L2 != nullptr)
    {
        ListNode *temp1 = L1->next;
        L1->next = L2;
        ListNode *temp2 = L2->next;
        L2->next = temp1;
        L1 = temp1;
        L2 = temp2;
    }
}