#ifndef LEET155_H
#define LEET155_H

#include "config.h"

class Solution155
{
public:
    /** initialize your data structure here. */
    Solution155()
    {
    }

    void push(int x);
    void pop();
    int top();
    int getMin();

private:
    std::stack<int> stk;
    std::stack<int> mins;
};

#endif