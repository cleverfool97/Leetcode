#include "036 - singleNumber.h"
#include "config.h"

using namespace std;

/*
Please refer to "36. Single Number" for the problem statement.

Solution:
    There are many ways to solve this problem, which may be added later on as alternate solutions.
    This particular solution leverages the fact that taking two of the same number and performing an XOR operation results in a 0.
    Given the input that we have, all you need to do is loop through once and XOR everything, then return that, since the singleton won't have something to cancel it.
    This algorithm thus performs in O(N)

Be Aware:
    -What are some other, more conventional ways to solve the problem?
    -What are the time complexities of such solutions?

Tests:
    -Array with just a singleton
    -Empty array
    -Any array with a random singleton in a random spot and a bunch of random number pairings
*/

int singleNumber(vector<int>& nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }

    return result;
}