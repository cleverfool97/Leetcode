#include "020 - validParentheses.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "20. Valid Parentheses" for the problem statement.

Solution:
    Every time we encounter an opening character, we know that its closing match must be next. 
    This requirement makes it attractive to use a stack to resolve the issue.
    We push open brackets onto it, and pop close brackets off, returning false if we have no open bracket to pop or if it doesnt match
    At the end we check to see if the stack has any remaining open brackets, and if not then we have a valid set!

Be Aware:
    -Is there any way to make this code prettier? If so, does it give a significant boost?
    -As with all switch statements, don't forget to include your break statements!

Tests:
    ""
    "[]"
    "["
    "]"
    "({[]})"
    "{{([]{}[{()[]}])}}"
*/
using namespace std;

bool Solution020::isValid(string s)
{
    stack<char> parenStack;
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case '(':
        case '[':
        case '{':
            parenStack.push(s[i]);
            break;
        case ')':
            if (!parenStack.empty() && parenStack.top() == '(') parenStack.pop();
            else return false;
            break;
        case ']':
            if (!parenStack.empty() && parenStack.top() == '[') parenStack.pop();
            else return false;
            break;
        case '}':
            if (!parenStack.empty() && parenStack.top() == '{') parenStack.pop();
            else return false;
        }
    }

    return parenStack.empty();
}