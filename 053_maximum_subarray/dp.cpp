class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        int max_value = dp[0];
        for(int i = 1; i<nums.size(); ++i){
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0) ;
            max_value = (max_value > dp[i] ? max_value : dp[i]);
        }
        return max_value;
    }
};
