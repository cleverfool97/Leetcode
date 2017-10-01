#include "033 - searchInRotatedSortedArray.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "33. Search in Rotated Sorted Array" for the problem statement.
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
Please refer to "153. Find Minimuim in Rotated Sorted Array" for more information on the algorithm to find the minimum in a rotated sorted array.

Solution:
    Perform a binary search for the location that the array was rotated to, then treat the array as if it was a normal one by doing a normal binary search accounting for the offset.
    We achieve this by finding the true middle in our actual search by adding the amount rotated mod by the size of the array to get the midpoint as if the array started from the offset.

    Let N be the size of the input array
    Time Complexity: O(logN), two binary searches
    Space Complexity: O(1), solution performed iteratively and not recursively with no additional data structures

Be Aware:
    -This solution can be coded recursively. If the solution isn't tail recursive, what does this mean for the space complexity once we start considering the call stack?
    -Why are we applying the modulus operator when setting the mid_rotated?

Tests:
    Empty Array
    [7,8,9,1,2,3]
    [1,2,3,4,5,6]
    [1]
    [2,1]
    [1,2,3,4,5,6,7]
    [4,5,6,7,1,2,3]
    [2,3,4,5,6,7,1]
*/

int Solution033::search(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }

    int rotation = low;
    low = 0;
    high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int mid_rotated = (mid + rotation) % nums.size();
        if (nums[mid_rotated] == target) return mid_rotated;
        if (nums[mid_rotated] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}