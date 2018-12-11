class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int max = 0;
        
        for(int i = 0; i < k; ++i){
            max += nums[i];
        }
        
        int temp_max = max;
        for(int i = k; i < n ; ++i){
            temp_max -= nums[i - k];
            temp_max += nums[i];
            max = (temp_max > max) ? temp_max : max;
        }
        
        return (max*1.0) / k;
    }
};
