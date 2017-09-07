#include "028 - implementStrstr.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "28. Implement Strstr" for the problem statement.

Solution:
    Fairly simple brute force search. For each possible starting point, check to see if the needle completes itself.
    Immediately return the index if it does so. On a mismatch, disregard the remaining characters and try the next index.
    
Be Aware:
    -LeetCode Discussion for this problem has a neat Knuth-Morris-Pratt algorithm that is theoretically faster than this solution. In practice, both complete the test cases in around 4 ms.
    -Don't forget to account for the empty needle case!
    -Time Complexity: O(H * L), where H is the length of the haystack and L is the length of the needle.

*/

int Solution028::strStr(string haystack, string needle)
{
    int needle_len = needle.length();
    int haystk_len = haystack.length();

    if (needle_len == 0) return 0;
    for (int i = 0; i <= haystk_len - needle_len; i++)
    {
        for (int j = 0; j < needle_len; j++)
        {
            if (haystack[i + j] != needle[j]) break;
            if (j == needle_len - 1) return i;
        }
    }

    return -1;
}