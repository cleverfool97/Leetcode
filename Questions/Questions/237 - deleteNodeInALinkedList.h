#ifndef LEET237_H
#define LEET237_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution237
{
public:
    void deleteNode(ListNode* node);
};
#endif
