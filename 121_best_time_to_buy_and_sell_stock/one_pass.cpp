class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_val = 32767;
        int tmp_diff;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < min_val) min_val = prices[i]; 
            tmp_diff = prices[i] - min_val;
            if(tmp_diff > ans) ans = tmp_diff;
        }
        return ans;
    }
};
