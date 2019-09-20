#include "242 - validAnagram.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "242. Valid Anagram" for the problem statement.
https://leetcode.com/problems/valid-anagram/description/

Solution:
    First check that the strings are the same length; they can't be anagrams of each other if not.
    Keep a hash table that maps characters to the number of appearances of that character, and track it for one of the strings.
    Then, for the second string, decrement the counter for each character, returning false if the entry is 0 (we are trying to use a letter that we don't have any left of in the first strring!).
    If we complete this loop, then we know that they are anagrams, because:
        Since they are the same string, if they are not anagrams there must exist a character in t that appears more often than in s.
        The conditional in the loop explicitly checks for this.

    Let N be the size of string S in characters.
    Time Complexity: O(N)
    Space Complexity: O(N)

Be Aware: 
    -An alternate approach is to sort both strings and check for equality.

    Time Complexity: O(NlogN)
    Space Complexity: O(1)

    -The solution here only beats 6.24% of submissions as of its last submission. Why might this be?

Tests:
    Two empty strings
    Two strings, different lengths
    "Leet, "code"
    "tommarvoloriddle", "iamlordvoldemort"
    "deltora", "toradel"
    "watchover", "overwatch"
    "abcd", "abec"
    "abcd", "abdd"
*/

bool Solution242::isAnagram(string s, string t)
{
    if (s.size() != t.size()) return false;

    unordered_map<char, int> occurrences;
    for (int i = 0; i < s.size(); i++)
    {
        occurrences[s[i]]++;
    }

    for (int j = 0; j < t.size(); j++)
    {
        if (occurrences[t[j]] == 0) return false;
        occurrences[t[j]]--;
    }

    return true;
}
