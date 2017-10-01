#include "066 - plusOne.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "66. Plus One" for the problem statement.

Solution:
    Initialize a carry to 1 to represent the 1 that we are adding, then propagate that carry through the digits array.

    Time Complexity: O(N), where N is the size of the digits vector
    Space Complexity: O(N), since a copy is made. If the intention is to modify the input array, this can be changed to use O(1) space
Be Aware:
    -Don't forget to consider that you might need to add a carry, if it remains at the end.
    -There is no push_front function in the C++ vector library.
Test Cases:
    1
    0
    9
    9, 9
    1, 9, 0
    2, 1, 9

*/
vector<int> Solution066::plusOne(vector<int>& digits)
{
    vector<int> result;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    if (carry) result.push_back(carry);
    reverse(result.begin(), result.end());
    return result;
}
