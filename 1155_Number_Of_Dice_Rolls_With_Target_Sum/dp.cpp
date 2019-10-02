class Solution {
public:
    /*
     * Complexity: O(d*f*target)
     * Space: O(d*target)
     */
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>dp(d + 1, vector<int>(target + 1));
        
        for(int k = 1; k <= min(f, target); ++k){        
            dp[1][k] = 1;
        }
        
        for(int i = 2; i <= d; ++i){
            for(int j = 1; j <= target; ++j){
                for(int k = 1; k <= f; ++k){
                    if(j > k){
                        dp[i][j] += dp[i-1][j-k];
                        dp[i][j] = dp[i][j] % (1000000007);
                    }
                }
            }
        }
        return dp[d][target];
    }
};
