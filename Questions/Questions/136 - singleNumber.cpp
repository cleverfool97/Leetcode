#include "136 - singleNumber.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "136. Single Number" for the problem statement.

Solution:
    There are many ways to solve this problem, which may be added later on as alternate solutions.
    This particular solution leverages the fact that taking two of the same number and performing an XOR operation results in a 0.
    Given the input that we have, all you need to do is loop through once and XOR everything, then return that, since the singleton won't have something to cancel it.

    Let N be the size of the input array.
    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -What are some other, more conventional ways to solve the problem?
    -What are the time complexities of such solutions?

Tests:
    -Array with just a singleton
    -Empty array
    -Any array with a random singleton in a random spot and a bunch of random number pairings
*/

int Solution136::singleNumber(vector<int>& nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }

    return result;
}