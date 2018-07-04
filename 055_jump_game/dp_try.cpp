class Solution {
/*
 * Complexity: O(n^2)
 * Space: O(n)
 */
public:
    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size());
        if(!nums.size()) return false;
        dp[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] && (i-j) <= nums[j]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp.back();
    }
};
