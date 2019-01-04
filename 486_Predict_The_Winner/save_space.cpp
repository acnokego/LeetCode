class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n); 
        // how much more points the first-action player would have considering nums[i..j]
    
        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(i == j){
                    dp[i] = nums[i];
                }
                else{
                    dp[j] = max(nums[j] - dp[j-1], nums[i] - dp[j]);
                }
                
            }
        }
        
        return dp[n-1] >= 0;
    }
};
