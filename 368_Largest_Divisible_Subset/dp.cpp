class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        vector<int>parent_idx(nums.size(), -1);
        vector<int>dp(nums.size(),1);
        int max_size = 0;
        int max_last_idx = -1;

        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j <= i-1; ++j){
                if(nums[i] % nums[j] == 0){
                    // find the max parent of i
                    if(dp[j] + 1 > dp[i]){
                        parent_idx[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            // find the max length of the array
            if(dp[i] > max_size){
                max_size = dp[i];
                max_last_idx = i;
            }
        }


        while(max_last_idx >= 0){
            ans.push_back(nums[max_last_idx]);
            max_last_idx = parent_idx[max_last_idx];
        }
        
        return ans;
    }
};
