#ifndef LEET021_H
#define LEET021_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution021
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};
#endif

