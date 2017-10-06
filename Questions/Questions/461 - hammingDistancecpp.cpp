#include "461 - hammingDistance.h"

/*
Difficulty: Easy
Please refer to "461. Hamming Distance" for the problem statement.
https://leetcode.com/problems/hamming-distance/description/

Solution:
    In this situation, since we know the data type and the range of values, we can figure out the number of bits we have to examine for any representation of input.
    Also, we can utilize the fact that if two bits are different, XOR'ing them together will produce 1.
    
    As such, we simply loop through each bit, examining one bit from each input, and adding the result of their XOR to a running tally.

    Time Complexity: O(1), loop will iterate 31 times
    Space Complexity: O(1)

Be Aware:
    -Are there faster or alternative ways to do this?
    -What if we didn't know the size in bits of the input?

Tests:
    1001
    1000

    1111
    0000

    1011
    0110
*/

int Solution461::hammingDistance(int x, int y)
{
    int result = 0;
    for (int i = 0; i < 31; i++)
    {
        int x_bit = x & 1;
        int y_bit = y & 1;
        result += x_bit ^ y_bit;
        x >>= 1;
        y >>= 1;
    }
    return result;
}
