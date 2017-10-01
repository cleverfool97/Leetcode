#include "258 - addDigits.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "258. Add Digits" for the problem statement.
Note: This code displayed here utilizes the mathematical concept of a digital root to implement the solution without recursion in O(1) runtime.
In an actual interview, knowing the recursive way is enough. Credit to LeetCode user zhiqing_xiao for noting this approach in the Discussion section for the question!

Alternate Solution:
    A more straightforward solution looks like this:
    
    int addDigits(int num)
    {
        if(num < 10) return num;
        return addDigits(num % 10 + addDigits(num / 10));
    }

    Here, the base case occurs when our input is a one digit-number. The recursive step reduces the problem by summing the ones place with an operation of itself divided by 10, which eventually becomes a sum of digits.
    This sum of digits may turn out to be greater than 10, so we perform a recursive call on this result to ensure that we don't need to continue the process on the result.
    This will eventually reduce to the answer.

Solution:
    Check out the digital root congruence formula here: https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
    
    Here it is, for quick reference (for a number n in base b):
        -dr(n) = 0                  if n == 0
        -dr(n) = (b - 1)            if n != 0 and n % (b - 1) == 0
        -dr(n) = n % (b - 1)        if n != 0 and n % (b - 1) != 0
    These three statements can then be reduced to a single statement:
        -dr_B(n) = 1 + (n - 1) % 9
    Examples:
        -Bullet 1 -> dr_B(0) = 1 + (-1) % 9 = 0
        -Bullet 2 -> dr_B(9) = 1 + (8) % 9 = 10 - 1 = 9
        -Bullet 3 -> dr_B(7) = 1 + (6) % 9 = 7 % 9 = 7

Be Aware:
    -Recall that decimal is base 10, so we are using 10 for the value of b in the digital root formula
    -Try comparing average runtimes for both solutions. Is the difference significant?
    -Typically writing the alternate solution here is more than enough. I include this solution as the main one because it's cool. ^_^

Tests:
    19
    1
    8
    56934
*/
int Solution258::addDigits(int num)
{
    return 1 + (num - 1) % 9;
}