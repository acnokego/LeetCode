class Solution {
public:
    /*
     * Complexity: O(n^2)
     * Space: O(n)
     */
    int findNumberOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        vector<pair<int, int>>dp(nums.size(), make_pair(1, 1)); // dp[i] : the max length of LIS stop at i, and the count of it
        pair<int, int>ans(make_pair(1,1));
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){              
                if(nums[j] < nums[i]){
                    if((dp[j].first + 1) > dp[i].first) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }else if ((dp[j].first + 1) == dp[i].first){
                        dp[i].second += dp[j].second;
                    }
                }
            }
            if(dp[i].first > ans.first){
                ans = dp[i];
            } else if (dp[i].first == ans.first) {
                ans.second += dp[i].second;
            }
        }
        return ans.second;
    }
};
