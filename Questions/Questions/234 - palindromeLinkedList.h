#ifndef LEET234_H
#define LEET234_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution234
{
public:
    bool isPalindrome(ListNode* head);
    ListNode* reverseList(ListNode* head);
};
#endif
