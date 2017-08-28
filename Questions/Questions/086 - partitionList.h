#ifndef LEET086_H
#define LEET086_H


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution086
{
public:
    ListNode* partition(ListNode* head, int x);
};
#endif
