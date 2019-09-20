#include "125 - validPalindrome.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "125. Valid Palindrome" for the problem statement.
https://leetcode.com/problems/valid-palindrome/description/

Solution:
    We start an iterator at the beginning, and one at the end, and match characters for both iterators. Anytime we don't have a match we immediately return false.
    If they pass each other without failing, then we have ourselves a valid palindrome.
    Note that in this case we pass over non alphanumeric characters and perform some processing on alphanumeric characters to make case irrelevant as well, as specified by the problem.

    Let N be the number of characters in the string.
    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -Don't forget that we defined an empty string to return true.
    -Remember to both decrement the backward iterator and increment the forward pointer if they match; each character needs to only be matched a single time.

*/


bool Solution125::isPalindrome(string s)
{
    if (s.size() == 0) return true;
    int forward = 0;
    int backward = s.size() - 1;

    while (forward < backward)
    {
        if (!isalnum(s[forward]))
        {
            forward++;
            continue;
        }

        if (!isalnum(s[backward]))
        {
            backward--;
            continue;
        }

        if (tolower(s[forward]) != tolower(s[backward])) return false;
        backward--;
        forward++;
    }

    return true;
}