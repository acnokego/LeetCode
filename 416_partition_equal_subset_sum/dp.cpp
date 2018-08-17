class Solution {
  /*
   * Complexity: O(n*half)
   * Space: O(half)
   */
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) sum += nums[i];
        if(sum % 2 != 0) return false;
        int half = sum / 2;
        vector<int>dp(half + 1, 0);
        dp[0] = 1;
        for(auto n : nums){
            // update the array from the back since it depends on the dp value at last iteration
            // if we update from the start the newest update value would be taken into consideration while updating.
            for(int i = half; i >= n; --i){
                // pick n || not pick n
                dp[i] = dp[i] || dp[i - n];
            }
        }
        return dp[half];
    }
};
