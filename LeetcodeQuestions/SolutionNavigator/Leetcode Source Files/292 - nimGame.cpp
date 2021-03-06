#include "292 - nimGame.h"
#include "config.h"

/*
Difficulty: Easy
Please refer to "292. Nim Game" for the problem statement.
https://leetcode.com/problems/nim-game/description/

Solution:
    The key is to leverage the hint that they give you: if you start with a 4, then no matter what you do you will lose since you have to go first.
    If you have 5, 6, or 7, you can reverse the situation and hand off the predicament to your friend who goes second, winning you the game.
    8 once again shifts the predicament back over to you, and so on and so forth.

    Thus, all you have to do is check to see if the input is divisible by 4. If it is, then you can't win. Otherwise you're fine!

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

bool Solution292::canWinNim(int n)
{
    return !(n % 4 == 0);
}