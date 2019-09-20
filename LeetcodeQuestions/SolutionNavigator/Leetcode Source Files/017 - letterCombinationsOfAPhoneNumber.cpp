#include "017 - letterCombinationsOfAPhoneNumber.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "17. Letter Combinations of a Phone Number" for the problem statement.
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
Credit to LeetCode user asbear for this solution + explanation, found here:
https://discuss.leetcode.com/topic/17262/iterative-c-solution-in-0ms

Solution:
    Backtracking
    Take advantage of the fact that the STL vector swap function is constant in time complexity.
    Initialize a vector that represents a mapping of digits to possible letters via index.
    For every digit in the input digit string, find the digit index by subtracting the char '0'.
    For every possible mapping, append each one to each string in temp.
    Swap temp and results, because temp currently represents the combinations up to the jth digit, which is what the j + 1 digit will build upon. Conveniently, this also represents the final result if there are no more digits remaining.

    Let N be the length of the digits string
    Time Complexity: TODO
    Space Complexity: TODO

Be Aware:
    -Make sure to confirm that your usage of library functions is not overly expensive!
    -Don't forget to account for the digits where there are no letter mappings and handle them appropriately

Tests:
    Empty String
    1234567890
    111
    2
    0
    1
    133431
*/

vector<string> Solution017::letterCombinations(string digits)
{
    vector<string> result;
    if (digits.size() == 0) return vector<string>();
    const vector<string> digit_mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    result.push_back("");

    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> temp;
        int dig_index = digits[i] - '0';
        if (dig_index == 0 || dig_index == 1) continue;
        for (int j = 0; j < result.size(); j++)
        {
            for (int k = 0; k < digit_mapping[dig_index].size(); k++)
            {
                temp.push_back(result[j] + digit_mapping[dig_index][k]);
            }
        }
        result.swap(temp);
    }


    return result;
}