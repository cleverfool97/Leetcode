#include "155 - minStack.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "155. Min Stack" for the problem statement.
https://leetcode.com/problems/min-stack/description/

Solution:
    We have two stacks; one to represent the contents of the minstack and another to represent a history of minimums in the stack.
    They will be called stk and mins, respectively.
    
    Mins will always have the minstack's minimum item at the top.

    push() - If mins is empty then whatever we add to stk should also be added to mins. Otherwise we only add to mins if the item is smaller than the current minimum at the top of the stack.
    pop() - Comare the item to be popped in stk with the item at the top of mins. If they match then the top of mins was added to mins when the item about to be popped off stk was added, so we should also pop off of mins (whew).
    top() - No change in functionality from a normal stack!
    getMin() - Corresponds to the most recent minimum in our history, which is identically the top of mins like we hoped.

Be Aware:
    -I modified the class declaration from MinStack to Solution155 to preserve the class numbering precedent I have set in the rest of the repository.
    -Credit to UCLA student Ying Bin Wu for providing the strategy for this solution!!
*/

/**
* Your MinStack object will be instantiated and called as such:
* Solution155 obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

void Solution155::push(int x)
{
    if (mins.empty() || x <= mins.top())
    {
        mins.push(x);
    }
    stk.push(x);
}

void Solution155::pop()
{
    if (!stk.empty() && !mins.empty() && stk.top() == mins.top()) mins.pop();
    stk.pop();
}

int Solution155::top()
{
    return stk.top();
}

int Solution155::getMin()
{
    return mins.top();
}
