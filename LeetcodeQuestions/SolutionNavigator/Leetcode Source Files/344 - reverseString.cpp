#include "344 - reverseString.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "344. Reverse String" for the problem statement.
https://leetcode.com/problems/reverse-string/description/

Solution:
    The first character will become the last, second the second to last, so on and so forth.
    Iterate forwards and backwards and swap appropriately, until the iterators meet halfway.
    Time Complexity: O(N)
    Space Complexity: O(1)
Be Aware:
    -There are many good ways to solve this problem.
    -Some companies like to use this question as a worksheet question at career fairs, because there are so many answers and it is relatively quick and easy.
    -This is a good warmup if it has been a long time since you have coded in a particular language.
Tests:
    ""
    "Hello world!"
    "A"
    "Even"
    "Odd"
*/

string Solution344::reverseString(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }

    return s;
}