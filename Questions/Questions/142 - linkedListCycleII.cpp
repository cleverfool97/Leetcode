#include "142 - linkedListCycleII.h"

/*
Difficulty: Medium
Please refer to "142. LinkedListCycle II" for the problem statement.

Solution:
    Credit to LeetCode user ngcl for this detailed algorithm explanation! 
    Check it out here: https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description

    We have a tortoise pointer that advances one node at a time.
    We have a hare pointer that advances two nodes at a time.
    If there exists a cycle, the hare will eventually catch up to the tortoise.
    At this point, the forward distance from the meeting point will be the same as the distance from the head to the meeting point.

    Proof:
    Let L1 be the distance from the head to the entry point of the cycle.
    Let L2 be the distance between the entry point and the meeting point (where the tortoise and hare next meet).
    Let C be the length of the cycle.
    Let n be the number of times the hare has traveled around the cycle when it meets the tortoise.

    When the two meet...
    The tortoise has traveled L1 + L2 nodes.
    The hare has traveled L1 + L2 + n * C nodes.
    
    Because the hare has traveled twice as far as the tortoise, we have...
    2 (L1 + L2) = L1 + L2 + n * C
    L1 + L2 = n * C
    L1 = (n - 1) * C + (C - L2)

    We realize that (n - 1) * C is just some number of whole cycle traversals, and that
    C - L2 is the remaining forward distance that you need to travel from the meeting point to return to the entry point.

    Because of this realization, if the tortoise and hare meet, we can just advance the tortoise and a pointer beginning at head until they are at the same spot.
    That spot will be the entry point of the cycle!

Be aware:
    -Watch out for nullptr access, especially when considering the hare.
    -In a real interview, you might not necessarily see this mathematical property immediately. It's important to try test cases and see if you can find a pattern.

Tests:
    -Empty list
    -List with no cycle.
    -List with the 2nd node as the entry point, cycle of size 3.
    -List with the 2nd node as the entry point, cycle of size 4.
    -List with the 2nd node as the entry point, cycle of size 5.
    -List with the 3rd node as the entry point, cycle of size 3.
    -List with the 3rd node as the entry point, cycle of size 4.
    -......
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

ListNode* Solution142::detectCycle(ListNode *head)
{
    ListNode *tortoise = head;
    ListNode *hare = head;

    while (hare != nullptr)
    {
        tortoise = tortoise->next;
        hare = hare->next;
        if (hare == nullptr) return nullptr;
        hare = hare->next;
        if (hare == tortoise)
        {
            ListNode *temp = head;
            while (temp != tortoise)
            {
                tortoise = tortoise->next;
                temp = temp->next;
            }
            return temp;
        }
    }

    return nullptr;
}