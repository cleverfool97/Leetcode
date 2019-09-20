#include "036 - validSudoku.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "36. Valid Sudoku" for the problem statement.
https://leetcode.com/problems/valid-sudoku/description/

Solution:
    We create three 9x9 arrays of booleans.
    Each row represents one of the 9 rows, columns, or squares of the board
    Each index represents whether that index + 1 has been used in the board yet. (e.g. rowUsed[4][7] represents whether 8 has been used yet in the 5th row).
    
    We iterate through the characters in the board. If we encounter a number, we check to see if it has been used for its row, column, or square yet. 
        If any, return false.
        Otherwise, we update all three to be used.

    If we make it through all squares without issue, then we can safely return true.

    Because the size of the Sudoku board is fixed to a 9x9 grid, we are using constant space and time for this function.
    Time Complexity: O(1)
    Space Complexity: O(1)

Be Aware:
    -k might be calculated a bit strangely here, but it is simply an equation that is used to ensure that elements within their square all map to the same numbering:

    0 1 2
    3 4 5
    6 7 8

Tests:
    A valid board that has some spaces
    A valid board that is completely empty
    A valid board that is completely solved
    An invalid board
*/

bool Solution036::isValidSudoku(vector<vector<char>>& board)
{
    bool rowUsed[9][9] = { 0 }, colUsed[9][9] = { 0 }, squareUsed[9][9] = { 0 };

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != '.')
            {
                int index = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if (rowUsed[i][index] || colUsed[j][index] || squareUsed[k][index]) return false;

                rowUsed[i][index] = colUsed[j][index] = squareUsed[k][index] = true;
            }
        }
    }

    return true;
}