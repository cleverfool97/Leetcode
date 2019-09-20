#ifndef LEET143_H
#define LEET143_H


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution143
{
public:
    void reorderList(ListNode* head);
};
#endif
