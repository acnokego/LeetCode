class Solution {
public:
    int climbStairs(int n) {
        std::vector<int>dp(n+1);
        if(n >= 1){
            dp[1] += 1;
            if(n >= 2) dp[2] += 2;
            else return 1;
        }
        else return 0;
        for(int i = 3; i < n+1; ++i){
            dp[i] += dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
