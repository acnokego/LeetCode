class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n^2)
   */
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n)); 
        // how much more points the first-action player would have considering nums[i..j]
        
        for(int i = 0; i < n; ++i){
            dp[i][i] = nums[i];
        }
        
        for(int diagonal = 1; diagonal < n; ++diagonal){
            for(int i = 0; i < n - diagonal; ++i){
                int j = i + diagonal;
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        
        return dp[0][n-1] >= 0;
    }
};
