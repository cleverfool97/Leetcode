#ifndef LEET141_H
#define LEET141_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution141
{
public:
    bool hasCycle(ListNode *head);
};
#endif