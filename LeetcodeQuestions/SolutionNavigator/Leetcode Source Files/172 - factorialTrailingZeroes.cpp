#include "172 - factorialTrailingZeroes.h"

/*
Difficulty: Easy
Please refer to "172. Factorial Trailing Zeroes" for the problem statement.
https://leetcode.com/problems/factorial-trailing-zeroes/description/

Solution:
    Recall that n! is simply n * n - 1 * n - 2 ... * 1
    Also, mathematically, every time we have an additional trailing zero we have effectively multiplied what we have by a factor of 10.
    Importantly, in factorials 5 will appear less often than 2, and since 2 * 5 is 10 we can count the number of trailing zeroes by counting the number of times we multiplied by 5.

    For each number in the range, we need to consider not only whether it contributes a 5, but how many.
    This can be done by dividing n by successive powers of 5.

    n/5 gets the number of numbers divisible by 5.
    n/25 gets the number of numbers divisible by 25. Note that the ones that are only divisible by 1 5 are not counted, and the ones that are divisible by 2 or more 5's are counted a second time.
    n/625 gets the numbe rof numbers divisible by 625. Note that the ones that are only divisible by 2 5's are not counted, and the ones that are divisible by 3 or more 5's are counted a third time.
    And so on...

    We keep doing this until n/5^i is 0, since that means that 5^i > n and there are no additional 5's left to count.

    Time Complexity: O(1)
    Space Complexity: O(1)

Be Aware:
    -You can cheese this problem by leveraging the constraints of representing n to get an O(1) solution. This doesn't translate to other situations, however.
    -Also note that this solution is also technically O(1), since the representation of the inputs limits how far the while loop can go.
    -Note that in this instance i is a long. This is to avoid overflow from repeatedly multiplying i by 5.

Tests:
    INT_MAX
    1
    5
    10
    247
*/

int Solution172::trailingZeroes(int n)
{
    int result = 0;
    long i = 5;
    while (n / i)
    {
        result += n / i;
        i *= 5;
    }

    return result;
}