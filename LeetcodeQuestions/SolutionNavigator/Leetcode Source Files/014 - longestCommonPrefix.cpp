#include "014 - longestCommonPrefix.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "14. Longest Common Prefix" for the problem statement.
https://leetcode.com/problems/longest-common-prefix/description/

Solution:
    The implemented approach is vertical scanning. That is, we look at every string's first character, then the 2nd, then the 3rd, and so on until we find an index where there is a mismatch.
    The benefit of this approach over horizontal scanning is that if there is a very short string at the end of the data set we will end much earlier than with horizontal scanning.
    However, in the worst case scenario both have the same complexity.
    Time complexity: O(MN), where M is the length of the longest string and N is the number of strings in the data set
    Space complexity: O(1), only using a single string for results storage
Be aware:
    -There are multiple solutions to this problem, including vertical scanning, horizontal scanning, and divide and conquer
    -Vertical scanning's complexity is about as minimal as you can get, however.
Tests:
    {"A", "B", "C"}
    {"AAA", "AAAA", "AAAB"}
    {"A", "AA", "AAA"}
    {"Overwatch", "Overcome", "Overdo", "Overpower"}
    {"man", "woman"}
*/

string Solution014::longestCommonPrefix(vector<string>& strs)
{
    if (strs.size() == 0) return "";
    string result = "";
    int max_prefix_len = INT_MAX;
    for (int i = 0; i < strs.size(); i++)
    {
        max_prefix_len = min(max_prefix_len, (int)strs[i].length());
    }

    for (int j = 0; j < max_prefix_len; j++)
    {
        char c = strs[0][j];
        for (int k = 0; k < strs.size(); k++)
        {
            if (strs[k][j] != c) return result;
        }
        result += c;
    }

    return result;
}
