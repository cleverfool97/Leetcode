#include "202 - happyNumber.h"


/*
Difficulty: Easy
Please refer to "202. Happy Number" for the problem statement.
https://leetcode.com/problems/happy-number/description/

Solution:
    We write a function to perform the digit sum square, then have a loop that has one that goes through the motions twice as fast as the other.
    If there is a loop that doesn't contain 1, then at some point after the starting point they will match again.
    Otherwise, once one of them hits 1, the other definitely will since 1 will keep producing itself.

    Time Complexity: TODO, however it will depend on math on the input.
    Space Complexity: O(1)

Tests:
    1
    19
    297
    4
*/


bool Solution202::isHappy(int n)
{
    int slow = n;
    int fast = n;
    do
    {
        slow = digitSumSquare(slow);
        fast = digitSumSquare(fast);
        fast = digitSumSquare(fast);
    } while (slow != fast);
    if (slow == 1) return true;
    return false;
}

int Solution202::digitSumSquare(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int remainder = n % 10;
        sum += remainder * remainder;
        n /= 10;
    }
    return sum;
}
