class Solution {
public:
    int numSquares(int n) {
        // dp[i] indicates the least number of square numbers which sum to i
        vector<int>dp(n+1);
        // iterative
        for(int i = 1; i < n+1; ++i){
            int min_num = 2147483647;
            // for each possible addition combinations
            for(int j = 1; j <= int(sqrt(i)); ++j){
                if(1 + dp[i - pow(j,2)] < min_num){
                    min_num = 1 + dp[i - pow(j,2)];
                }
            }
            dp[i] = min_num;
        }
        return dp[n];        
    }
};
