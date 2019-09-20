#ifndef LEET019_H
#define LEET019_H

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
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution019
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
};

#endif
