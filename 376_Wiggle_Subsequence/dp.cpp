class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2)); // the maxLength of subsequence we can have for nums[0...i-1]
        // the second dimension: 0 -> positive, 1 -> negative
        
    
        dp[0][0] = dp[0][1] = 1;
        
        int ans = min(1, n);
        
        for(int i = 1; i < n; ++i){
            
            // see whether the incoming number make the previous subsequence change direction
            // only have to calulate the distance between nums[i] and nums[i-1]
            //
            // Let's say dp[i-1][0] doesn't end with nums[i-1], it ends with
            // nums[i'] (0 <= i' < i). It indicates that nums[i'+1] ~ nums[i-1] 
            // are all bigger than nums[i'] (increasing) so we only have to 
            // compare nums[i-1] with nums[i] to see whether the direction would
            // change.
            
            int diff = nums[i] - nums[i-1];
            if(diff < 0){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][0] + 1;
            }
            else if(diff > 0){
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = dp[i-1][1];
            }
            else{
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
            
            ans = max(dp[i][0], max(dp[i][1], ans));
        }
        
        return ans;
      
    }
};
