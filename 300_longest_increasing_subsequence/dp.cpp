class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int>dp(nums.size(),1);
        int ans = 1;
        for(int i = 0; i < nums.size(); ++i){
            int tmp_max = -2147483647-1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j] && dp[j] > tmp_max) tmp_max = dp[j];
            }
            if(tmp_max > 0) dp[i] += tmp_max;
            if(dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};
