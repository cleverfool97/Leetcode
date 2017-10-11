#include "200 - numberOfIslands.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "200. Number of Islands" for the problem statement.
https://leetcode.com/problems/number-of-islands/description/

Solution:
    Iterate through the grid. Every time we encounter a 1, we increment our island counter, then BFS outwards to mark all other 1's in this island as 0, so we don't double count.

    Let N be the number of characters in the grid.
    Time Complexity: O(N). Each index can only be marked by the BFS one time, since after it is marked it will never be input to the function again. Each index is visited one time by the main double for loop.
*/

int Solution200::numIslands(vector<vector<char>>& grid)
{
    int result = 0;
    if (grid.size() == 0) return 0;
    if (grid[0].size() == 0) return 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                result++;
                markByBFS(grid, i, j);
            }
        }
    }

    return result;
}

void Solution200::markByBFS(vector<vector<char>>& grid, int x, int y)
{
    grid[x][y] = '0';
    if (x > 0 && grid[x - 1][y] == '1') markByBFS(grid, x - 1, y);
    if (x < grid.size() - 1 && grid[x + 1][y] == '1') markByBFS(grid, x + 1, y);
    if (y > 0 && grid[x][y - 1] == '1') markByBFS(grid, x, y - 1);
    if (y < grid[0].size() - 1 && grid[x][y + 1] == '1') markByBFS(grid, x, y + 1);
}