#include "022 - generateParentheses.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "22. Generate Parentheses" for the problem statement.
https://leetcode.com/problems/generate-parentheses/description/

Solution:
    This represents a good example of a backtracking problem, mixed with knowledge of STL functions and data structures.

    For a given length n, we realize that we just need all the different ways to add one pair of parentheses to each of the results produced for n - 1.
    Thus, it makes sense to attempt an approach where we start with just the single pair of parentheses and build upwards.
    However, while we build up, we want to be sure that we aren't considering duplicate cases. An STL data structure that doesn't keep duplicates is the set.

    Finally, we also keep in mind that if for iteration i we produce result_i, then for the next iteration we should produce result_i+1 based off result_i.
    How do we actually achieve this in code? We can use the STL swap function, which operates in constant time, to switch our running result with a temporary vector that stores the results for each iteration.

    Thus, we have 3 nested loops:
        -The first loop tells us what n to stop at
        -The second loop is a loop through the set of all parentheses combinations we have generated so far
        -The third loop is a loop through the length of each parentheses combo to try to insert "()". 

    Note that if left unchecked, this approach would produce tons of duplicates. Hence why the usage of a set is so important here!

    Let N be the integer passed into the function call.
    Time Complexity: Very big, depndendent on the number of actual parentheses combinations that can be produced.
                     Note that logically, we would be minimally constrained by having to produce every combination.
    Space Complexity: O(N) for the temporary vector

Be Aware:
    -Make sure you are tracking what temp and result are storing at any given time. Don't mistime your swaps!
    -For those overwhelmed by the sheer number of possibilities, try considering a brute force way of knowing for sure you have considered every possibility.

Tests:
    0
    3
    12
    25
*/

vector<string> Solution022::generateParenthesis(int n)
{
    if (n <= 0) return vector<string>();

    set<string> parens;
    parens.insert("()");
    for (int i = 2; i <= n; i++)
    {
        set<string> temp;
        for (set<string>::iterator j = parens.begin(); j != parens.end(); j++)
        {
            for (int k = 0; k < (*j).size(); k++)
            {
                string new_item = *j;
                new_item.insert(k, "()");
                temp.insert(new_item);
            }
        }
        parens.swap(temp);
    }

    return vector<string>(parens.begin(), parens.end());
}