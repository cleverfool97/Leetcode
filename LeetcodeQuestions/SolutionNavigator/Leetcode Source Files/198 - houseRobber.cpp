#include "198 - houseRobber.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "198. House Robber" for the problem statement.
https://leetcode.com/problems/house-robber/description/

Solution:
    -Dynamic Programming
    -For a given house k, the best answer is either: 
        -loot at house k + max money robbed excluding previous house
        -max of money robbed including previous house or money robbed including previous house
    Hence, the solution is to keep a temp variable that holds the previous "include", then continually update them until you reach house N at the end.
    The best value will either be include or exclude!
    -Time Complexity: O(N)
    -Space Complexity: O(1)
Be aware:
    -This question, despite an Easy tag, requires some knowledge of Dynamic Programming. It's also a reasonably tricky one to understand.
    -Make sure that you correctly translate your recurrence to code!
Tests:
    []
    [1]
    [1,2]
    [2,1]
    [2,1,1,2]
*/
int Solution198::rob(vector<int>& nums)
{
    int include = 0;
    int exclude = 0;
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        temp = i;
        include = nums[i] + exclude;
        exclude = max(temp, exclude);
    }

    return max(include, exclude);
}