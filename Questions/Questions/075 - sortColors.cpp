#include "075 - sortColors.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "75. Sort Colors" for the problem statement.

Solution:
    Instead of actually sorting, because there are so few different kinds of elements in the data set, we just keep a count of each one and then add them in via simple loops afterwards.

    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -Normally a sorting algorithm can at best be O(NlogN), because O(N) time is only enough to iterate through an unsorted array. However, in this case we achieve a better solution since we know information about the data set.

Tests:
    []
    [1]
    [0]
    [2]
    [1,0,2]
    [0,0,1,2,2,2]
    [1,0,1,2,1,2]
*/


void Solution075::sortColors(vector<int>& nums)
{
    int reds = 0, whites = 0, blues = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        switch (nums[i])
        {
        case 0:
            reds++;
            break;
        case 1:
            whites++;
            break;
        case 2:
            blues++;
            break;
        default:
            return;
        }
    }

    int index = 0;
    for (int r = 0; r < reds; r++)
    {
        nums[index] = 0;
        index++;
    }

    for (int w = 0; w < whites; w++)
    {
        nums[index] = 1;
        index++;
    }

    for (int b = 0; b < blues; b++)
    {
        nums[index] = 2;
        index++;
    }
}