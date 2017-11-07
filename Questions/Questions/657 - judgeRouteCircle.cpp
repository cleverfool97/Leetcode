#include "657 - judgeRouteCircle.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "657. Judge Route Circle" for the problem statement.
https://leetcode.com/problems/judge-route-circle/description/

Solution:
    Keep two counters, one for the amount moved up/down and the other for the amount moved left/right.
    Iterate through the string, making the appropriate addition/subtraction to the appropriate counter.
    Afterwards, both counters should be 0. Otherwise our robot has moved to a different location!

    Let N be the length of the input string
    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -This is a very simple problem that should take < 5 minutes in an interview.
    -It doesn't matter what you add or subtract, so long as left is opposite of right with equal weight and up is opposite of down with equal weight.

Tests:
    UD
    DU
    LR
    RL
    U
    L
    RRLLUDUDLRLRRLLR
    UURRDLLRLDR
    Empty string
*/

bool Solution657::judgeCircle(string moves)
{
    int up = 0;
    int right = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        switch (moves[i])
        {
        case 'U':
            up++;
            break;
        case 'D':
            up--;
            break;
        case 'L':
            right--;
            break;
        case 'R':
            right++;
        }
    }

    return up == 0 && right == 0;
}