class Solution {
  /*
   * Complexity: O(n*S) ?
   * Space: O(n*S)
   */
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        
        vector<unordered_map<int, int>>dp(n+1);
        // dp[i][j] : considering index before ith with sum j, the total number of ways
        dp[0][0] = 1;
        for(int i = 0; i < n; ++i){
            // only consider the sum that has occurred
            for(auto& it : dp[i]){
                dp[i+1][it.first + nums[i]] += it.second;
                dp[i+1][it.first - nums[i]] += it.second;
            }
        }
        return dp[n][S];
    }
};
