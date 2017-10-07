#include "023 - mergeKSortedLists.h"
#include "config.h"

using namespace std;

/*
Difficulty: Hard
Please refer to "23. Merge k Sorted Lists" for the problem statement.
https://leetcode.com/problems/merge-k-sorted-lists/description/

Solution:
    Let k be the number of sorted lists we have.
    Let N be the total number of elements we have across all lists.

    Our solution is to use a minheap that keeps pointers to non-nullptr nodes sorted in ascending order by the value stored within said nodes.
    Thus, in order to access the next smallest item when building our merged list, it will only cost O(1) time to access, and then O(k) to handle adding the next node and removing the one just considered.
    Because we are building a merged list, we will need to visit each node one time, so each node will be a part of this minheap at some point (it needs to be the next item in order to be merged in).
    Thus...

    Time Complexity: O(NlogK)
    Space Complexity: O(k)

Be Aware:
    -There are a multitude of ways to solve this problem. For example, one can scan the front of each linked list to find the smallest element to add. This removes the need for a heap.
     However, it's time complexity becomes O(Nk)

Tests:
    Empty Set
    5 lists each with 1 item
    5 lists, all but one with no items
    [1,4,7,10], [2, 5, 8, 11, 13], [3, 6, 9, 12, 14, 15], [16], [17, 19]
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<ListNode*, vector<ListNode*>, LessThanByVal> q;
    ListNode* sentinel = new ListNode(0);
    ListNode* cur = sentinel;

    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i] != nullptr)
        {
            q.push(lists[i]);
        }
    }

    while (!q.empty())
    {
        ListNode* nextElement = q.top();
        cur->next = nextElement;
        cur = cur->next;
        q.pop();
        if (nextElement->next != nullptr) q.push(nextElement->next);
    }

    return sentinel->next;
}

