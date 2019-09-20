#include "300 - longestIncreasingSubsequence.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "300. Longest Increasing Subsequence" for the problem statement.
https://leetcode.com/problems/longest-increasing-subsequence/description/

Solution:
    Credit to Leetcode user DietPepsi with a similar explanation of this problem.
    https://discuss.leetcode.com/topic/28738/java-python-binary-search-o-nlogn-time-with-explanation

    Our tails array stores the smallest tail for all increasing subsequences of length i + 1 in tails[i]

    We see that as we iterate through our numbers, there will be one of two scenarios:
        -if x is larger than any of our tails, we can append it to our existing subsequences. This essentially means x will be in tails[i + 1], if our longest increasing sequence has so far been in tails[i]
        -if tails[i - 1] < x <= tails[i], update tails[i], update tails[i]. Since we can construct a sequence that's length i + 1 that ends with something greater than x, and the smallest tail right before is less than x, it is safe to replace whatever is in tails[i] with x.

    From this, we can easily see that the answer at the end will be size that tails managed to get to.

    Because the tails array is increasing, we can reason that for each element in nums, we are performing a binary search.
    Thus, if N is the size of the nums array,

    Time Complexity: O(NlogN)
    Space Complexity: O(N)

Be Aware:
    -The library function lower_bound returns an element pointing to the first element in the range [first, last) which does not compare less than val. It operates in logN time.
    -This is a classic dynamic programming problem!

Tests:
    Empty vector
    [1]
    [1, 2]
    [10, 9]
    [10, 9, 2, 5, 3, 7, 101, 18]
    [1, 2, 3, 4, 5]
    [5, 4, 3, 2, 1]
    [1, 9, 2, 8 , 3, 7, 4, 6, 5]
*/

int Solution300::lengthOfLIS(vector<int>& nums)
{
    vector<int> tails;
    tails.reserve(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        auto loc = lower_bound(tails.begin(), tails.end(), nums[i]);
        if (loc == tails.end()) tails.push_back(nums[i]);
        else *loc = nums[i];
    }

    return tails.size();
}
