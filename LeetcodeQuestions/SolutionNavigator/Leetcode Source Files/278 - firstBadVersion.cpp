#include "278 - firstBadVersion.h"

/*
Difficulty: Easy
Please refer to "278. First Bad Version" for the problem statement.
https://leetcode.com/problems/first-bad-version/description/

Solution:
    Use a binary search to narrow down your search to a single bad version.
    Consider the middle item:
    If it is a bad version, then we know that the first bad version must be in the left half, including mid
    If it is not a bad version, then we know that the first bad version must be in the right half, not including mid
    We continue the search, narrowing the search space by half until the lower bound passes by the upper bound and we have arrived at our answer.

    Let N be the integer input
    Time Complexity: O(logN), total API calls O(logN)
    Space Complexity: O(1)

Be Aware:
    -Another solution, which simply involves beginning at the start and continuing until a bad version is encountered, could potentially perform N API calls.
    -Though the API function is not shown to the user in the question officially, I have included a trivial one for the sake of allowing this code to compile. Don't make assumptions about the API implementation!

Tests:
    1 as first bad version (FBV), 5 versions
    3 as FBV, 5 versions
    4 as FBV, 5 versions
    5 as FBV, 5 versions
    256 as FBV, 513 versions
*/


int Solution278::firstBadVersion(int n)
{
    int lower = 1, upper = n, mid;
    while (lower < upper)
    {
        mid = lower + (upper - lower) / 2;
        if (!isBadVersion(mid)) lower = mid + 1;
        else upper = mid;
    }
    return lower;
}


bool Solution278::isBadVersion(int n)
{
    return n >= 25;
}