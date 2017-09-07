#include "056 - mergeIntervals.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "56. Merge Intervals" for the problem statement.

Solution:
    We sort the interval vector by increasing start time.
    Then, beginning at the first interval, we keep merging start times that fall within the end bounds, and updating the end bounds if it increases.
    Whenver we encounter an interval that is outside of the end bounds, we set a new start and end bound for another interval that will be in our result.

    Total time complexity: O(NlogN)

Be Aware:
    -Functions that are intended to be used by std::sort must be declared as static in c++
    -This assumes that the std::sort function implements a sorting algorithm that runs in NlogN time
    -Use the keyword const if you want the function to promise that it won't modify the input contents.
*/

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

static bool sortByStart(const Interval& a, const Interval& b)
{
    return a.start < b.start;
}

vector<Interval> Solution056::merge(vector<Interval>& intervals)
{
    vector<Interval> result;
    if (intervals.size() == 0) return result;
    sort(intervals.begin(), intervals.end(), sortByStart);

    int curStart = intervals[0].start;
    int curEnd = intervals[0].end;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start > curEnd)
        {
            Interval toAdd(curStart, curEnd);
            result.push_back(toAdd);
            curStart = intervals[i].start;
            curEnd = intervals[i].end;
        }
        else if (intervals[i].end > curEnd) curEnd = intervals[i].end;
    }

    Interval straggler(curStart, curEnd);
    result.push_back(straggler);

    return result;
}
