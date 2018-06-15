class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int>dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i< amount + 1; ++i){
            for(int j = 0; j<coins.size(); ++j){
                if(i >= coins[j] && dp[i-coins[j]] >= 0){
                    if(dp[i] > 0) dp[i] = min(1 + dp[i-coins[j]], dp[i]);   
                    else dp[i] = 1 + dp[i-coins[j]];
                }
            }
        }
        return dp.back();
    }
};
