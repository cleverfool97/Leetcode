#include "054 - spiralMatrix.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Refer to "54. Spiral Matrix" for the problem statement.

Solution:
    We traverse the 2D array like we would follow it on paper: start at the top left corner and just wrap around.
    We keep track of a left, right, top, and bottom index. Every time we complete a "line" in our spiral traversal, we modify the indices to match.
    The final solution has a time complexity of O(MN), which is unavoidable because we must visit every index once anyway.
Be Aware:
    -This is an exercise in traversal and index tracking; there are a variety of ways to do this.
    -Watch out for out of bound errors.
Test Cases:
    -Empty array.
    -Array with one row
    -Array with one element
    -Array with multiple columns of 1 item rows
    -5x5
    -5x6
    -6x6
    -6x5
*/
vector<int> Solution054::spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;
    if (matrix.size() == 0) return result;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        int r = left;
        while (r <= right)
        {
            result.push_back(matrix[top][r]);
            r++;
        }
        top++;
        if (top > bottom) return result;
        int d = top;
        while (d <= bottom)
        {
            result.push_back(matrix[d][right]);
            d++;
        }
        right--;
        if (left > right) return result;
        int l = right;
        while (l >= left)
        {
            result.push_back(matrix[bottom][l]);
            l--;
        }
        bottom--;
        int u = bottom;
        while (u >= top)
        {
            result.push_back(matrix[u][left]);
            u--;
        }
        left++;
    }

    return result;

}