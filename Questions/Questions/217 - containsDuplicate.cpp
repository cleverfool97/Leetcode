#include "217 - containsDuplicate.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "217. Contains Duplicate" for the problem statement.

Solution:
    We initialize a set and begin iterating through the array of numbers.
    As we encounter values, we check if the set already holds the value. If so then we return true since we have just found a duplicate!
    Otherwise, we add the value to the set so that the set will catch future occurrences of this value.
    If we reach the end of the array without returning true that means every array entry had a distinct value, so we should return false.

    Time Complexity: O(N), where N is the size of the array
    Space Complexity: O(N), where N is the size of the array (in a situation where we reach the end of the for loop, the set will contain every item in nums, which were all distinct)

Be Aware:
    -Recall that a set in the STL doesn't contain duplicates

Tests:
    []
    [1]
    [1,1]
    [1,2,2,3]
    [2,1,3,6,5,4,7]
    [2,1,3,8,5,1,7]
*/

bool Solution217::containsDuplicate(vector<int>& nums)
{
    set<int> encountered;
    for (int i = 0; i < nums.size(); i++)
    {
        if (encountered.find(nums[i]) != encountered.end())
        {
            return true;
        }
        encountered.insert(nums[i]);
    }
    return false;
}