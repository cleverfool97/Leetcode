#include "412 - fizzBuzz.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "412. Fizz Buzz" for the problem statement.
https://leetcode.com/problems/fizz-buzz/description/

Solution: 
    This is a very basic algorithm. Just loop through from 1 up until n and examine the number, adding the appropriate string to your result as you go.

    Time Complexity: O(n)
    Space Complexity: O(n), just for storing the result

Be Aware:
    -This is a good example of simplicity vs performance. This code is not necessarily the most efficient code in terms of runtime. However, it is very easy to read.

Tests:
    Call with n = 31 to get a good spread of all conditional branches.

*/
vector<string> Solution412::fizzBuzz(int n)
{
    vector<string> result;

    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0) result.push_back("FizzBuzz");
        else if (i % 5 == 0) result.push_back("Buzz");
        else if (i % 3 == 0) result.push_back("Fizz");
        else result.push_back(to_string(i));
    }

    return result;
    
}