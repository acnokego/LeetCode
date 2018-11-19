class Solution {
  /*
   * Complexity: O(n ^ target)
   * Space: O(target)
   */
public:
    int recursive(vector<int>& nums, int target, vector<int>& dp){ 
        if(dp[target] != -1){
            return dp[target];
        }
        
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > target) break;
            ans += recursive(nums, target - nums[i], dp);
        }
        
        dp[target] = ans;
        return ans;
                     
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>dp(target + 1, -1);
        dp[0] = 1;
        return recursive(nums, target, dp);
        
    }
};
