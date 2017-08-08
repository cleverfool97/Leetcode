#ifndef LEET142_H
#define LEET142_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution142
{
public:
    ListNode* detectCycle(ListNode *head);
};
#endif
