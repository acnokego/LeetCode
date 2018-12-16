class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        else if(n == 1) return nums[0];
        
        // dp[i][j], the maximum value when considering nums[0...i-1], j indicate the first house is robbed or not
        vector<vector<int>>dp(n, vector<int>(2));
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = dp[0][1];
        
        for(int i = 2; i < n; ++i){
            
            dp[i][0] = max(dp[i-1][0], dp[i-2][0] + nums[i]);
            
            if(i != (n - 1)){
                dp[i][1] = max(dp[i-1][1], dp[i-2][1] + nums[i]);
            }
            // for the last house, if the first house is robbed, we cannot rob the last one.
            else{
                dp[i][1] = dp[i-1][1];
            }
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
