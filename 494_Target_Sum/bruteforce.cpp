class Solution {
  /*
   * Complexity: O(2^n)
   * Space: O(n)
   */
public:
    void recursive(vector<int>&nums, int idx, int S, int tmp_sum, int & ans){
        if(idx == nums.size()){
            if(tmp_sum == S) ++ans;
            return;
        }
        int neg = -1*nums[idx];
        recursive(nums, idx + 1, S, tmp_sum + neg, ans);
        recursive(nums, idx + 1, S, tmp_sum + nums[idx], ans);
        return;
        
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        recursive(nums, 0, S, 0, ans);
        return ans;
    }
};
