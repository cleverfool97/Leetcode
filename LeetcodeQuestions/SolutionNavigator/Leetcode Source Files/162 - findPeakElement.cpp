#include "162 - findPeakElement.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "162. Find Peak Element" for the problem statement.
https://leetcode.com/problems/find-peak-element/description/

Solution:
    This is a binary search problem.
    The key is to realize that given that the left and right bounds are negative infinity and mid, there must exist a peak and that peak can be found in one of the halves.

    In the search:
    First, we check the element at mid against its left and right to see if we have found a peak. If so, we can return right away.
    Otherwise, we know for sure that either the left or the right element was larger.
    A peak MUST exist on the side with the larger element, because there already exists a value with a smaller value on either side.

    One might be tempted to immediately try the larger value to check if it is a peak, but it actually makes the solution more complicated and less efficient.

    If we consistently use this methodology, each time we are halving the range that we know that a peak must exist, effectively creating our log(N) solution.

    Time Complexity: O(logN)
    Space Complexity: O(1)

Be Aware:
    -Note that in this case we don't need to find the global peak. Any peak that follows the definition will do, and there can be many of them in the input data.

Tests:
    [1, 3, 1, 4, 2]
    [1]
    [-1]
    [-3, -1, -2]
    [0, 1, 2]
    [2, 1, 0]
    [1, 3, 2, 4, 5, 6, 7, 9, 8]
*/

int Solution162::findPeakElement(vector<int>& nums)
{
    if (nums.size() == 1) return 0;
    if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid == 0 && nums[mid + 1] < nums[mid]) return mid;
        else if (mid == nums.size() - 1 && nums[mid - 1] < nums[mid]) return mid;
        else if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) return mid;
        else if (nums[mid - 1] > nums[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return mid;
}