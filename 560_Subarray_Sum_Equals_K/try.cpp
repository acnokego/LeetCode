class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(1)
   */
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int start = 0, end = 0;
        int n = nums.size();
        
        while(start < n){
            int tmp_sum = 0;
            while(end < n){
                tmp_sum += nums[end];
                if(tmp_sum == k){
                    ans += 1;
                }
                ++end;
            }
            ++start;
            end = start;
        }
        
        return ans;
        
    }
};
