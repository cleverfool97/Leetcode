#include "001 - twoSum.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to Leetcode's "Two Sum" for the problem statement.
https://leetcode.com/problems/two-sum/description/

Solution:
    The basic principle is to create a hashMap of ints to ints with a number as a key and its index in the given vector as the value.

    We begin with such a data structure without any items inside.
    Iterate through the provided vector
        -If the number in the considered spot has its counterpart that sums to the target in the hashmap, return that stored index and the current index as the solution.
        -Otherwise, add the current <number, index> pair to the hashmap and continue iterating.
    Proceed until completed.

    Let N be the size of the input array
    Time Complexity: O(N^2), one iteration of the for loop, each insertion worst case O(N). However, in practice this will be much closer to O(1)
    Space Complexity: O(N), assuming a solution pair exists then worst case N - 1 <int, int> pair entries will be added.
*/
vector<int> Solution001::twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    unordered_map<int, int> hashMap;

    for (int i = 0; i < nums.size(); i++)
    {
        if (hashMap.count(target - nums[i]) != 0)
        {
            result.push_back(hashMap.find(target - nums[i])->second);
            result.push_back(i);
            break;
        }

        hashMap.insert(pair<int, int>(nums[i], i));
    }

    return result;
}

