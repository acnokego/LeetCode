class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            // if the value of the index is already negative (occurred before)
            if(nums[abs(nums[i]) - 1] > 0) ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};
