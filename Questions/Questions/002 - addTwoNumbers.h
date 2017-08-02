#ifndef LEET002_H
#define LEET002_H

#include "config.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

class Solution002
{

public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

};


#endif
