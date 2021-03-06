#include "055 - jumpGame.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "55. Jump Game" for the problem statement.
https://leetcode.com/problems/jump-game/description/

Solution:
    Utilize a greedy approach. Begin at the start, initialize the max index you can reach from the start, and iterate through the array.
    If at any point the number stored at an index would push back how far you can move, update the max reachable index.
    If you can no longer iterate any further and you have passed the max index without exceeding the target (the end), then it isn't possible to reach the end.

    Let N be the size of the input array.
    Time Complexity: O(N), currentMax is set to nums.size() - 2 and reached by i, but the end is not reached
    Space Complexity: O(1), just some integers to keep track of locations

Be Aware:
    -This problem is a good demonstration of how to utilize looping to get a good solution.
    -This is a good example of a greedy algorithm. Why is it intuitively good to try a greedy solution in this case?

Tests:
    -Reachable
    -Unreachable
*/
bool Solution055::canJump(vector<int>& nums)
{
    int target = nums.size() - 1;
    int currentMax = 0;

    int i = 0;
    while (i <= currentMax)
    {
        if (i + nums[i] > currentMax) currentMax = i + nums[i];
        if (i >= target) return true;
        i++;
    }

    return false;
}