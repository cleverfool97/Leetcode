#include "003 - longestSubstringWithoutRepeatingCharacters.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "3. Longest Substring Without Repeating Characters" for the problem statement.
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Solution:
    You can obviously brute force it by calculating everything, but this will take too much time.
    You can apply a dynamic programming paradigm here, and try to find a recurrence.
    If we consider adding a character, the longest substring without a repeating character in the first N characters of the input string can be:
        1. The optimal answer from the first N - 1 characters, which DOESN'T include the Nth character.
        2. The answer that DOES include the Nth character.
    Sample Recurrence:
        OPT(n) -> max(OPT(n - 1), n - indexWithLatestRepeatedCharacter))

    Let N be the length of the input string
    Time Complexity: O(N), assuming constant time library functions, otherwise O(N^2) (find_last_of will take at most O(N) time)
    Space Complexity: O(N), vector to keep track of longest substring up to that point.

Be Aware:
    -This solution has room for improvement! The initialization is not quite clean and the library function find_last_of technically can run in O(N), though it generally will be close to constant.
    -However, as of 8/2/2017, this solution beats 78% of .cpp submissions on LeetCode, supporting the hypothesis that find_last_of has good average runtime.
    -Dynamic programming solutions generally take extra space, but save in time.
    -The latest repeated character is not necessarily going to be the Nth character you are considering. ex: ABBA.

Test Cases:
    ""
    "A"
    "AB"
    "abcabcbb"
    "pwwkew"
    "bbbbbbbbb"
*/

int lengthOfLongestSubstring(string s) 
{
    if (s.size() == 1) return 1;
        
    vector<int> optimals(s.length() + 1, 0);
    int potential, repeatIndex = 0;
    for(int i = 1; i < s.length(); i++)
    {
        potential = s.find_last_of(s[i], i - 1) + 1;    //New character might move up the index of the last repeat
        if(potential != string::npos && potential > repeatIndex) repeatIndex = potential;
        optimals[i + 1] = max(optimals[i], i - repeatIndex + 1);
    }
        
    return optimals[s.length()];     
}
