class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   *
   * Using the preSum hash, we are able to know the number of arrays
   * starting from index 0 that has sum equal to (sum - k). Meanwhile, we would
   * know that the number of subarrays have sum k is equal to that number in hash.
   */
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int sum = 0;
        unordered_map<int, int>preSum;
        preSum[0] = 1;
        
        for(int i = 0; i < n; ++i){
            sum += nums[i]; // the cumulative sum[0...i]
            ans += preSum[sum - k]; // if sum[0...j] = sum - k, then sum[j+1...i] is the subarray we want
            preSum[sum] += 1;          
        }
        return ans;
        
    }
};
