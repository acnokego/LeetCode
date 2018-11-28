class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n; ++i){
            // negative number indicate the element of that index value has showed up
            int idx = abs(nums[i]) - 1;
            nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
        }
        
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0) ans.push_back(i+1);
        }
        
        return ans;
    }
};
