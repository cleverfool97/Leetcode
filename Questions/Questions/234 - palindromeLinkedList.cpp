#include "234 - palindromeLinkedList.h"

/*
Difficulty: Easy
Please refer to "234. Palindrome Linked List" for the problem statement.
Please refer to "206. Reverse Linked List" for more information on the reverseList function

Solution:
    Find the beginning of the second half by having a scout pointer that iterates twice as fast as another pointer, which will point at the second half once the scout reaches the end of the LL.
    Reverse that half
    Now, beginning from the start and the half, iterate through both and compare values, returning false if the values fail to match.
    If we make it through both halves then we return true

    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -This solution performs modifications on the list, then undoes them before returning. Is there a solution that eliminates the need to do this?
    -Make sure to consider the case where the linked list is of odd length

Tests:
    Empty list
    1
    1->1
    1->2->1
    1->2->2->1
    1->2->3->4->5
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

bool Solution234::isPalindrome(ListNode* head)
{
    ListNode *tortoise = head;
    ListNode *hare = head;

    //Find start of second half, without including middle node for an odd length LL
    while (hare != nullptr)
    {
        tortoise = tortoise->next;
        hare = hare->next;
        if (hare != nullptr) hare = hare->next;
    }

    //Reverse second half
    ListNode *secondHalf = tortoise;
    tortoise = reverseList(tortoise);

    //Check second half
    ListNode *temp = head;
    while (tortoise != nullptr)
    {
        if (temp->val != tortoise->val)
        {
            reverseList(secondHalf);
            return false;
        }
        temp = temp->next;
        tortoise = tortoise->next;
    }

    reverseList(secondHalf);
    return true;


}

ListNode* Solution234::reverseList(ListNode* head)
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
