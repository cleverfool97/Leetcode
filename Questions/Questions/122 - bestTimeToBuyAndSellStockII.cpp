#include "122 - bestTimeToBuyAndSellStockII.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "122. Best Time to Buy and Sell Stock II" for the problem statement.

Solution:
    Because this time there is no limit to the number of times the stock can be purchased and sold, we simply add all the days where we can make a profit by buying that day and selling the next.
    Situations:    
        -Small, Large, Medium: Profit captured in Small->Large
        -Small, Medium, Large: Max profit is still Small->Large, however we capture this in the code with Small->Medium followed by Medium->Large
        -Medium, Small, Large: Ignore Medium
        -Medium, Large, Small: Max profit captured in Medium->Large
        -Large, Small, Medium: Max profit captured in Small->Medium
        -Large, Medium, Small: No profit can be gained
Be Aware:
    -This question is nontrivial, and is indeed a test of clarity as well. Depending on the wording of the problem it can be interpreted as a different problem entirely.
    -Refer to the Discussion page for this problem; previously the wording made it appear there were additional restrictions.
*/
int Solution122::maxProfit(vector<int>& prices)
{
    int result = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] - prices[i - 1] > 0) result += prices[i] - prices[i - 1];
    }
    return result;
}