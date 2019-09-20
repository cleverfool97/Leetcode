#include "074 - searchA2DMatrix.h"
#include "config.h"

using namespace std;


/*
Difficulty: Medium
Please refer to "74. Search a 2D Matrix" for the problem statement.
https://leetcode.com/problems/search-a-2d-matrix/description/

Solution:
    The basic principle is a 2 layer binary search. First we find the row that the target would have to exist in.
    Then we binary search within that row (if we find it, otherwise we'll have already returned) to try to find the target.

    Let M be the number of rows in the matrix, and N be the number of columns in the matrix
    Time Complexity: O(logM) + O(logN)
    Space Complexity: O(1)

Be Aware:
    -Though the solution has two nested while loops, the time complexity is still posted above.
    -The reason why it isn't O(logM)O(logN) is because we are only binary searching by column in at most one row.
    -Note that O(logM) + O(logM) = O(log(MN)), which is the log of the number of items in the matrix, the same time complexity as if we were binary searching a sorted array.

Tests:
    Target in (4,4) of 4x4 matrix
    Target greater than largest value of matrix
    Target smaller than smallest value of matrix
    Target not in matrix, but between last element of row 1 and first element of row 2
    Target in (1,1) of 4x4 matrix
    Target in (2,3) of 4x4 matrix
    Target in (5,1) of 10x1 matrix

*/

bool Solution074::searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    int m_low = 0;
    int m_high = m - 1;

    while (m_low <= m_high)
    {
        int m_mid = m_low + (m_high - m_low) / 2;
        if (matrix[m_mid][n - 1] < target) m_low = m_mid + 1;
        else if (matrix[m_mid][0] > target) m_high = m_mid - 1;
        else
        {
            int n_low = 0;
            int n_high = n - 1;
            while (n_low <= n_high)
            {
                int n_mid = n_low + (n_high - n_low) / 2;
                if (matrix[m_mid][n_mid] == target) return true;
                else if (matrix[m_mid][n_mid] > target) n_high = n_mid - 1;
                else n_low = n_mid + 1;
            }
            break;
        }
    }

    return false;
}