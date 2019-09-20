#include "045 - jumpGameII.h"
#include "config.h"

using namespace std;

/*
Difficulty: Hard
Please refer to "45. Jump Game II" for the problem statement.
https://leetcode.com/problems/jump-game-ii/description/

Solution:
    We utilize a greedy approach. It's very similar to Jump Game I. However, this time we know for sure we can reach the end.
    The trick is to keep track of the furthest distance you can get on your current jump, and a tally of jumps that you have performed.
    Whenever we reach the furthest index we can do in one jump, we increment the jumps counter since further distance requires another jump.
    The furthest distance that we can reach at this point is the new furthest distance we can achieve with the next jump.

    Time Complexity: O(N)
    Space Complexity: O(1)

    Credit to LeetCode user ChengZhang for this delightful solution!

Tests:
    TODO
*/


int Solution045::jump(vector<int>& nums)
{
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        curFarthest = max(nums[i] + i, curFarthest);
        //We reached the last index that we can reach for this jump
        if (i == curEnd)
        {
            jumps++;
            curEnd = curFarthest;
        }
    }

    return jumps;
}
