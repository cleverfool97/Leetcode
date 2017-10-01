#include "121 - bestTimeToBuyAndSellStock.h"
#include "config.h"

using namespace std;

/*
Difficulty: Easy
Please refer to "121. Best Time to Buy and Sell Stock" for the problem statement.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

Solution:
    We initially consider the case where we buy on the first day and sell on the very next day.
    We can then iterate through the remaining days to eventually find the maximum profit we can make. Here's how:
        -Keep track of our current max profit and the lowest price encountered so far (or an index to it) 
        -If we encounter a day with a price lower than our current lowest price, update our lowest price; any sale in the future would be better with a buy on this day than at what was tracked before.
        -If we encounter a day with a price higher than our current lowest price, it is a potential sell day. Compare the price difference to the current max profit, and update if necessary.

    Let N be the size of the input array.
    Time Complexity: O(N)
    Space Complexity: O(1)

Be Aware:
    -There are tons of variations of this problem, ranging across all difficulties.
    -Don't forget that there exists a scenario where it's better to never buy!

Test Cases:
    [1,2,3,4,5]
    [1]
    [1,2]
    [2,1]
    [2,4,1,5]
*/

int Solution121::maxProfit(vector<int>& prices)
{
    if (prices.size() < 2) return 0;

    int result = prices[1] - prices[0];
    int buy_ind = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < prices[buy_ind])
        {
            buy_ind = i;
        }
        else
        {
            result = max(result, prices[i] - prices[buy_ind]);
        }
    }

    return max(result, 0);
}