#include "419 - battleshipsInABoard.h"
#include "config.h"

using namespace std;

/*
Difficulty: Medium
Please refer to "419. Battleships in a Board" for the problem statement.
https://leetcode.com/problems/battleships-in-a-board/description/

Solution:
    This can be solved by marking battleships using either BFS or DFS; however, we can leverage what we know about their positioning to get a faster solution.

    We know that a ship of length N will occupy either a 1xN row or a Nx1 column.
    We also know that ships will not be adjacent to each other; that is, there is either a border or water between all battleships.
    
    This means that we can iterate through the board and count certain X's because they denote NEW battleships. Other X's that don't fit the criteria are part of battleships that have already been counted.

    If we go top to bottom, left to right, we know that we are part of a new battleship if we encounter an X and neither the slot directly above or to the left of it is an X.
    We simply count the number of these X's to get the number of battleships on the board.

    Time Complexity: O(N)
    Space Complexity: O(1)
    Advantages: 1 pass, no board modification

Be Aware:
    -Why can't we use this trick in other BFS/DFS board problems?
    -If we were to iterate bottom to top, right to left, what would need to change about the X's that we are counting?

Tests:
    X..X
    ...X
    XX..

    X

    ..
    ..

    .....
    .XX.X
    ....X
    ..X..
    ....X
*/

int Solution419::countBattleships(vector<vector<char>>& board)
{
    int count = 0;
    if (board.size() == 0) return 0;
    if (board[0].size() == 0) return 0;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'X')
            {
                if ((i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X')) count++;
            }
        }
    }

    return count;
}