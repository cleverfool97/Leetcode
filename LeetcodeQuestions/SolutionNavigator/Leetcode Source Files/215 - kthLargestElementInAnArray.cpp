#include "215 - kthLargestElementInAnArray.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "215. Kth Largest Element in an Array" for the problem statement.
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Solution:
    Transform the underlying array into a maxheap, then pop off items until the top contains the kth item. Maxheaps provide easy access to the maximum item as well as quick updates for when items are removed.

    Time Complexity: TODO
    Space Complexity: TODO

Be Aware:
    -Always be mindful of costs when using STLs.

Alternate Solutions:
    https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively
    Major credit to LeetCode user jianchao.li.fighter for having such an excellent write up with 4 solutions, including the one I came up with!

Tests:
    [1], 1
    [1,2], 1
    [2,1], 1
    [2,1], 2
    [1,7,2,3,6], 4
*/

int Solution215::findKthLargest(vector<int>& nums, int k)
{
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 1; i < k; i++)
    {
        pq.pop();
    }

    return pq.top();
}