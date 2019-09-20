#include "540 - singleElementInASortedArray.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "540. Single Element in a Sorted Array" for the problem statement.
https://leetcode.com/problems/single-element-in-a-sorted-array/description/

Solution:
    The trivial answer would simply be to iterate through the array and find the first number that doesn't have its twin next to it.

    However, it can be done faster, via binary search, leveraging the fact that there are no duplicate pairs (e.g. [4,4,4,4,5] will never appear).
    Whenever we consider a element at a midpoint in our binary search, we first check to see if is the single element by looking at the elements on either end.
    If it isn't it, then we determine which half to go to by figuring out if we have passed the single element or not.

    Data: [1,1,2,2,3,4,4,5,5]
    Index:[0,1,2,3,4,5,6,7,8]

    Notice that if we haven't passed the singleton, the first twin falls on an even index and the second falls on an odd index.
    However, if we have passed the singleton then the first twin falls on an odd index and the second falls on an even index.
    Using this, and the parity of the midpoint we are considering, we can check if we have passed the singleton or not, effectively determining which half we should consider.

    Time Complexity: O(logN)
    Space Complexity: O(1)

Be Aware:
    -What if we were allowed to have duplicate pairings? Would this algorithm still work? Why or why not?

Tests:
    [1,2,2,3,3]
    [1,1,2,2,3]
    [1,1,2,3,3]
    [1]
    [1,1,2]
    [1,1,2,2,3,3,5,5,9]
*/

int Solution540::singleNonDuplicate(vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;
    if (nums.size() == 1) return nums[0];

    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid == 0 && nums[mid + 1] != mid) return nums[mid];
        if (mid == nums.size() - 1 && nums[mid - 1] != nums[mid]) return nums[mid];
        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) return nums[mid];

        if (mid % 2 == 0)
        {
            if (nums[mid + 1] != nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else
        {
            if (nums[mid - 1] != nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
    }

    return nums[low];
}