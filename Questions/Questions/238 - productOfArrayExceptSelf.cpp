#include "238 - productOfArrayExceptSelf.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "238. Product of Array Except Self" for the problem statement.

Solution:
    Keep an aggregate product going forwards, and an aggregate product going backwards, and update each array spot by multiplying by this aggregate product.
    In order to avoid having the ith location include its element in the product, we only update the aggregates AFTER multiplying them in.
    That way, for the ith item in an array of size n...
        -The forwards aggregate is nums[0]...nums[i - 1]
        -The backwards aggregate is nums[i + 1]...nums[n - 1]
        -Multiplying these aggregates together provides the desired result at each stage

    Time Complexity: O(N), where N is the size of the input array (two loops through the array)
    Space Complexity: O(1) (two integers; NOTE: problem specifies that output array doesn't count as extra space)

Be Aware:
    -This solution, like many solutions, shows that often times an immediately expensive solution (say, O(N) space and O(N) time) can in fact be very similar to the optimal solution.
    -This is why it is important to find SOME solution in an interview, because often times with a few hints a better solution will reveal itself.

Tests:
    [1,1]
    [2,3]
    [1,2,3,4]
    [2,4,6,8,10]
    [1,10,8,4,7]
*/

vector<int> Solution238::productExceptSelf(vector<int>& nums)
{
    vector<int> output(nums.size(), 1);
    int forward = 1;
    for (int i = 0; i < output.size(); i++)
    {
        output[i] *= forward;
        forward *= nums[i];
    }

    int backward = 1;
    for (int j = output.size() - 1; j >= 0; j--)
    {
        output[j] *= backward;
        backward *= nums[j];
    }
    return output;
}
