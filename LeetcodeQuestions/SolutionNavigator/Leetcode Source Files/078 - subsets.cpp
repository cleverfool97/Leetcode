#include "078 - subsets.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "78. Subsets" for the problem statement.
https://leetcode.com/problems/subsets/description/

Solution:
    Backtracking
    Each number either exists in a subset or it doesn't. We iterate through the numbers.
        -At index i, we have all the subsets generated from 1 to i - 1. These represent half of the subsets in the range 1 to i. 
        -The other half is simply this half, except with the number at index i included in each one.
        -Thus, for each iteration we go back to what we have in the solution and add items appropriately.
    
    Time Complexity: O(2^N), where N is the number of items in the input vector. 2^N subsets are generated.
        -Remember each number stored at the ith index is either in a given subset, or not.
    Space Complexity: O(2^N), to hold the result

Be aware:
    -These kinds of problems can be intimidating because there are so many outputs to keep track of. Keep a level head and try to find a procedure to generate what you need!
    -Set theory is a very interesting topic in Discrete Mathematics. Knowledge of this topic can help with some of the more mathy coding questions.

Tests:
    []
    [1,2,3,4]
    [2,3,5]
*/

vector<vector<int>> Solution078::subsets(vector<int>& nums)
{
    vector<vector<int>> result;
    result.push_back({});

    int last = result.size();
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < last; j++)
        {
            vector<int> element = result[j];
            element.push_back(nums[i]);
            result.push_back(element);
        }
        last = result.size();
    }

    return result;
}