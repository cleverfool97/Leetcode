#ifndef LEET057_H
#define LEET057_H

#include "config.h"

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution057
{
public:
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval);
};
#endif
