class Solution {
/*
 * Complexity: O(n^2)
 * Space: O(1)
 */
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int tmp_diff;
        for(int i = 0; i < prices.size(); ++i){
            for(int j = i; j < prices.size(); ++j){
                tmp_diff = prices[j] - prices[i];
                if(tmp_diff > ans) ans = tmp_diff;
            }
        }
        return ans;
    }
};
