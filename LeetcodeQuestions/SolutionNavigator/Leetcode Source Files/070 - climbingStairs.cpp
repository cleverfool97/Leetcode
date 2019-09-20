#include "070 - climbingStairs.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "70. Climbing Stairs" for the problem statement.
https://leetcode.com/problems/climbing-stairs/description/

Solution:
    This is a classic dynamic programming problem. For any stair number i, we arrived there with 1 step from the step below, or with 2 steps from 2 below.
    Thus, if that is denoted as OPT[n], we can use the recurrence OPT[n] = OPT[n - 1] + OPT[n - 2].
    Note that the solutions for each part are mutually exclusive because all of the ones in OPT[n - 1] get a 1 step at the end and all of the ones in OPT[n - 2] get a 2 step at the end.
    
    Time Complexity: O(N), where N is the integer number specified by the input.
    Space Complexity: O(1)
    
    Base case for 1 step is 1 since you can only take a 1 step move.
    Base case for 2 step is 2 since you can do 1,1 or a single 2 step.

Be Aware:
    -Though the question is ranked Easy, you might have some trouble if you haven't yet learned Dynamic Programming. It's a very neat topic!

Tests:
    1
    2
    3
    6
*/
int Solution070::climbStairs(int n)
{

    if (n == 1) return 1;
    if (n == 2) return 2;

    int twoStepsDown = 1;
    int oneStepDown = 2;
    int result = 0;

    for (int i = 3; i <= n; i++)
    {
        result = twoStepsDown + oneStepDown;
        twoStepsDown = oneStepDown;
        oneStepDown = result;
    }

    return result;
}