class Solution {
public:
    int integerBreak(int n) {
        // the maximum product we can have for each value previous than n
        vector<int>dp(n);
        for(int i = 1; i < n; ++i){
            // base case
            if(i == 1) dp[i] = 1;
            else{
                // considering only the value itself
                dp[i] = i;
                // considering breaking into at least two numbers
                for(int j = i-1; j >= i / 2; --j){
                    dp[i] = max(dp[i], dp[j]*dp[i-j]); 
                }
            }
        }
        
        int ans = 0;
        for(int i = n - 1; i >= n / 2; --i){
            ans = max(ans, dp[i]*dp[n-i]);
        }
        return ans;
    }
};
