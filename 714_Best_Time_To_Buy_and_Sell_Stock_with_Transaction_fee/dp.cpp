class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        vector<int>buy(size, 0); //max profit in day i in buy status (last op)
        vector<int>sell(size, 0); // max profit in day i in sell status (last op)
        
        buy[0] -= prices[0];
        
        for(int i = 1; i < size; ++i){
            buy[i] = max(buy[i-1], sell[i-1] - prices[i]); // in previous state or buy the ith stock to be in the buy status
            sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee); // in previous selle state or sell the stock to be in sell status
        }
        return sell[size - 1];
    }
};
