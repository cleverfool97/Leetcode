#include "041 - firstMissingPositive.h"
#include "config.h"

using namespace std;

/*
Difficulty: Hard
Please refer to "41. First Missing Positive" for the problem statement.
https://leetcode.com/problems/first-missing-positive/description/

Solution:
    The problem stipulates that we cannot use any extra space, yet the problem would be so trivial if we could!
    Think: for an array of size n, the first missing positive must be n + 1 at the very most (assuming the array contains identically the first n positive integers.
    Think, we simply initialize an array of bools of the same length as the input.
    Then, iterate through the input array. Every time we encounter a value within the range, we set the bool corresponding to its index to true.
    Then, iterate through the bool array, and return the index of the first index to contain false, else we return n + 1 since that's the first missing positive.

    Time Complexity: O(N)
    Space Complexity: O(N)

    How do we make this solution better?
    Turns out, we can just use the existing array and swap values in place as we go along, using the exact same principle!
    Numbers above n and 0 or less are irrelevant, since none of them can possibly be the first missing positive.

    Whenever we consider the ith element and are about to make a swap, we need to take care that we address two things:
        -The item that gets swapped with the ith item may also itself require swapping.
        -If the item that got swapped with the ith item is a duplicate of the ith item, we could get stuck in an endless loop of swaps. We don't want that.

    Addressing both issues in the conditional of the while loop we have ourselves an O(N) time, O(1) space solution!

    Let N be the size of the input vector.
    Time Complexity: O(N), note that the inner while loop will perform at most N swaps in total for the entire execution of the function.
    Space Complexity: O(1)

Be Aware:
    -This solution modifies the input vector. Would we still be able to have an O(1) space solution if we weren't allowed to?
    -Make sure to understand why this solution is still O(N) time despite the fact that it has a nested while loop.\

Tests:
    [1,2,3,4]
    []
    [2]
    [3, -2, 1, 4, 5, -22]
    [8, 12, 14, -1, 0, 2]
*/


int Solution041::firstMissingPositive(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != j + 1)
            return j + 1;
    }

    return nums.size() + 1;
}