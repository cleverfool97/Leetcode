#include "169 - majorityElement.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "169. Majority Element" for the problem statement.
https://leetcode.com/problems/majority-element/description/

Solution:
    Since we know there is a majority element, we can match each appearance of such an element with one that is not and cancel them out.
    Even after all non-majority elements are cancelled we will still have some majority elements left.
    Thus, we just keep track of what our current candidate for the majority element is and a count.
    Each time we encounter another instance, we increment the count.
    Each time we encounter an instance we aren't tracking, we decrement the count.
    If at any point the count is 1 and we need to decrement, we simply swap the candidate with the number we just encountered that caused the decrement.

    Time Complexity: O(N), where N is the size of the input vector
    Space Complexity: O(1), only requires two integers

Be Aware:
    -Note that swapping the number we consider is the equivalent of two non-matching numbers "cancelling" each other out
    -Keep in mind the problem states that the input is not empty

Test Cases:
    [1,1,1]
    [1,1,2]
    [1]
    [1,1,2,2,3,3,4,4,1]
*/


int Solution169::majorityElement(vector<int>& nums)
{
    int current = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == current) count++;
        else
        {
            if (count == 1)
                current = nums[i];
            else
                count--;
        }
    }

    return current;
}