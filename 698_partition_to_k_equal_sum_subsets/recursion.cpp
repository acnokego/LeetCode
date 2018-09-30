class Solution {
  /*
   * Complexity: O(n * 2^n)
   * Space: O(n)
   */
public:
    bool dfs(vector<int>& nums, vector<bool>& used, int k, int start, int curr_sum, int target){
        if(k == 1) return true;
        // find subset in nums not visited
        if(curr_sum == target) return dfs(nums, used, k-1, 0, 0, target);
        // find subset that is equal to target 
        for(int i = start; i < nums.size(); ++i){
            if(!used[i]){
                used[i] = 1;
                if(dfs(nums, used, k, i+1, curr_sum + nums[i], target)) return true;
                used[i] = 0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || n < k) return false;
        int sum = 0;
        for(auto& num : nums){
            sum += num;
        }
        // if the sum cannot be divided by k, return false
        if(sum % k != 0) return false;
        sum /= k; // sum for each subset
        vector<bool>used(n, 0);
        return dfs(nums, used, k, 0, 0, sum);
    }
    
};
