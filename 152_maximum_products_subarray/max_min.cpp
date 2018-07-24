class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   * reference:
   * https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
   */
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = nums[0];
        /*
         * i_max stores the maximum products of subarray ending at i
         * i_min stores the minimum products of subarray ending at i
         */
        int i_max = ans, i_min = ans;
        for(int i = 1; i < n; ++i){
            // if it is negative then i_max, i_min should swap
            if(nums[i] < 0) swap(i_max, i_min);
            // check if the current value is larger than its product with
            // previous values.
            i_max = max(nums[i], nums[i] * i_max);
            i_min = min(nums[i], nums[i] * i_min);
            ans = max(ans, i_max);
        }
        return ans;
    }
};
