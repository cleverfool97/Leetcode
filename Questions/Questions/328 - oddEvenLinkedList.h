#ifndef LEET328_H
#define LEET328_H

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};
class Solution328
{
public:
    ListNode* oddEvenList(ListNode* head);
};
#endif
