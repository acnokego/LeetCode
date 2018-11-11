class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
 
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        if(!s) return 0;
        // before i-th day, the max profit we get if the last operation is buy (ignore cooldown)
        int buy[s] = {0};
        // before i-th day, the max profit we get if the last operation is sell(ignore cooldown)
        int sell[s] = {0};
        // need to buy in the beginning so that we can sell
        buy[0] = -prices[0];
        for(int i = 1; i < s; ++i){
            // if we don't have to cooldown, not sell before (i-2 < 0), just find the minumum
            // starting point to buy
            buy[i] =(i-2 >= 0) ? max(sell[i-2] - prices[i], buy[i-1]) : max(-prices[i], buy[i-1]);
            // sell the previous, or do nothing.
            sell[i] = max(buy[i-1] + prices[i], sell[i-1]);
        }
        return sell[s-1];
    }
};
