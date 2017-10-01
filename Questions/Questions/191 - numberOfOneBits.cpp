#include "191 - numberOfOneBits.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "191. Number of 1 Bits" for the problem statement.

Solution:
    So long as our input is nonzero, we know that there is still a 1 bit to be counted, so we continually check the least significant bit and rightshift it away, maintaining a count of 1's that we encounter.

    Time Complexity: O(1), while loop only goes for as many iterations as bits in the input
    Space Complexity: O(1)

Be Aware:
    -This is a simple way to refresh on bitshifting if you are rusty.
Tests:
    0
    INTMAX
    11
    2^5
    2^5 - 1
    2^5 - 1 + 2^20
*/

int Solution191::hammingWeight(uint32_t n)
{
    int result = 0;
    while (n > 0)
    {
        if (n & 1 == 1) result++;
        n >>= 1;
    }
    return result;
}
