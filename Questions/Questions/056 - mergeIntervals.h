#ifndef LEET056_H
#define LEET056_H

#include "config.h"

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution056
{
public:
    std::vector<Interval> merge(std::vector<Interval>& intervals);
};
#endif
