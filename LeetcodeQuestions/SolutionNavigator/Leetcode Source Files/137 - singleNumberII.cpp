#include "137 - singleNumberII.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "137. Single Number II" for the problem statement.
https://leetcode.com/problems/single-number-ii/description/

Solution:
    There are many ways to solve this problem, including:
        -Brute force, O(N^2)
        -Hash table appearance counter, O(N) time, O(N) space
        -Determine whatever equivalent operation as the XOR to find the singleton in O(N).
    This solution solves the problem in O(N) time using constant memory. Credit to Prathyush Katukojwala for coming up with the idea for this!!

    The XOR trick in 136 no longer works, since 3x and 1x are both odds, so XORs cannot cancel copies out nicely.
    We can instead count the number of times each bit is set for each of the 32 bits in an int, and mod that by 3 to get 1 in all the places where the bit is set
    in the correct answer.

Be Aware:
    -Don't mix math operations and bit operations if you can help it. It can produce weird interactions when dealing with negative numbers.
    -The integer in this solution is a 32 bit value where the bit at the kth (starting from 0) represents 2^k. The most significant bit is negative to allow
     for negative number representations.

Tests:
    -Array with just one number
    -Array with negative singleton, various triplets
    -Array with positive singleton, various triplets
    -Array with only negative numbers
    -Array with only positive numbers
*/
int Solution137::singleNumber(vector<int>& nums)
{
    vector<int> resultBits(sizeof(int) * 8, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        int current = nums[i];
        for (int j = 0; j < sizeof(int) * 8; j++)
        {
            resultBits[j] += current & 1;
            current >>= 1;
        }
    }

    int result = 0;
    for (int k = 0; k < resultBits.size(); k++)
        result |= ((resultBits[k] % 3) << k);    
    return result;
}