class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = INT_MIN, buy2 = INT_MIN; // the maximum profit we have now if we do the buy 
        int sell1 = 0, sell2 = 0; // the maximum profit we have if we do sell (first/ second)
        
        for(int p : prices){
            sell2 = max(sell2, buy2 + p);
            buy2 = max(buy2, sell1 - p);
            sell1 = max(sell1, buy1 + p);
            buy1 = max(buy1, -p);
        }
        
        return sell2;
    }
};
