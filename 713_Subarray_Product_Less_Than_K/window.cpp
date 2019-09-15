class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     * 
     * If the product of arr[start:end] is smaller than k, the would be total
     * (end - start + 1) subarrays (end at each positions) in arr that is smaller
     * than k.
     * Increasing the sliding window until the product is bigger than k, then
     * moving the starting point forward.
     */
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        
        int ans = 0;
        if(!size) return ans;
        int start = 0, product = 1;
        for(int end = 0; end < size; ++end){
            product *= nums[end];
            while(start <= end && product >= k){
                product /= nums[start++];
            }
            ans += (end - start + 1);
        }
        return ans;
    }
};
