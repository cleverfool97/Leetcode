#include "057 - insertInterval.h"
#include "config.h"

using namespace std;

/*
Difficulty: Hard
Please refer to "57. Insert Interval" for the problem statement.
https://leetcode.com/problems/insert-interval/description/

Solution:
    We are given that the intervals are sorted by start time.
    Thus, we can iterate through the array of intervals once to insert our new interval, such that our array is still in sorted order.
    The issue then remains that merging might have to occur.

    They essentially reduce to these two situations:
        -The interval right before where we inserted the interval might have an end that surpasses the start point of our inserted interval, requiring merging.
        -Every interval after the interval that we inserted might have a start point that is surpassed by the end point of our inserted interval, also requring merging.

    Fortunately for us, this can be done in a second pass through the array.

    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -Don't forget to account for the case where our array of intervals began as an empty array!
    -Make sure you understand the time complexity of your STL functions. In this case, vector insert is linear on number of items inserted and items after its insertion location. Because we insert once at most and it could be at the start, it still falls within O(N) time.
    -Also note that {[1,5], [6, 8]} is a valid interval set that doesn't require any merging.

Tests:
    Empty vector
    {[1, 3], [6, 7]}, [3, 4]
    {[1, 3], [7, 10], [12, 15]} [4, 24]

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

vector<Interval> Solution057::insert(vector<Interval>& intervals, Interval newInterval)
{
    if (intervals.empty())
    {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
    }

    bool insertAtEnd = true;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i].start > newInterval.start)
        {
            intervals.insert(intervals.begin() + i, newInterval);
            insertAtEnd = false;
            break;
        }
    }
    if (insertAtEnd) intervals.insert(intervals.end(), newInterval);

    for (int j = 0; j < intervals.size() - 1; j++)
    {
        if (intervals[j].end >= intervals[j + 1].start)
        {
            intervals[j].end = max(intervals[j].end, intervals[j + 1].end);
            intervals.erase(intervals.begin() + j + 1, intervals.begin() + j + 2);
            j--;
        }
    }

    return intervals;
}