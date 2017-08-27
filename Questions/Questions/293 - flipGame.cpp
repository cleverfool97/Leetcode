#include "293 - flipGame.h"
#include "config.h"

using namespace std;

/*
Please refer to "293. Flip Game" for the problem statement. Note that this problem is available for premium Leetcode users only.

Solution:
    Simply iterate through the string, and at any point there are consecutive '+' symbols change the pair to '-' and add that representation to the result.
Be aware:
    -There are more efficient ways to perform the mechanics of what is happening here. Using library calls is not always efficient.
Tests:
    Empty
    ++++
    -+-+-
    ++--+++
    +-+--++-
    -
    +
*/
vector<string> Solution293::generatePossibleNextMoves(string s)
{
    vector<string> result;
    for (int i = 0; i < (int)s.length() - 1; i++)
    {
        if (s[i] == '+' && s[i + 1] == '+')
        {
            string temp = s;
            temp.replace(i, 2, "--");
            result.push_back(temp);
        }
    }

    return result;
}