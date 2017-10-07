#ifndef LEET023_H
#define LEET023_H

#include "config.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct LessThanByVal
{
    bool operator()(ListNode* &a, ListNode* &b)
    {
        return (a->val > b->val);
    }
};

class Solution023
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists);
};

#endif