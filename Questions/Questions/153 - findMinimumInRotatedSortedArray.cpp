#include "153 - findMinimumInRotatedSortedArray.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "153. Find Minimum in Rotated Sorted Array" for the problem statement.

Solution:
    Initially we check to make sure that there in fact is a rotation.
    If so, we begin looping through and finding the value stored at the midpoint.
    If the midpoint's value is greater than the leftmost value, then we haven't passed the rotation point yet and we eliminate the left half.
    If the midpoint's value is less than the leftmost value, then we already passed the rotation point and we eliminate the right half.
    We continue onwards until we have narrowed our search to 1 location.

    Time Complexity: O(logN)
    Space Complexity: O(1), performed iteratively with no additional data structures.

Be Aware:
    -There is a recurisve solution to this problem. Why might a recursive solution not be as good as this one, in terms of space complexity?

Tests:
    []
    [1]
    [1,2,3,4,5,6]
    [3,4,5,6,7,8,1,2]
    [3,4,5,6,7,1,2]
*/

int Solution153::findMin(vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;
    if (nums[low] < nums[high]) return nums[low];
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }

    return nums[low];
}