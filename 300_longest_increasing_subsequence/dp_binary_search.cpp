class Solution {
/*
 * Complexity: O(nlgn)
 * Space: O(1) using the original nums array
 *  AMAZING SOLUTION!!!
 *
 *  do a single pass through nums as we check each elements:
 *  - The length of S will be equal to the length of the longest subsequence 
 *  I've found to that point.
 *  - The last element of S will be the last element of that subsequence. 
 *  (However, the earlier elements may no longer be part of that sequence -- 
 *  S is not actually the subsequence itself.)
 *  At the end, the length of S will be the solution.
 *
 *
 *  S will be sorted at all times. Each new element is inserted into S, 
 *  replacing the smallest element in S that is not smaller than it 
 *  (which we can find using binary search). If that element is larger than 
 *  the last element of S, then we extend S by one -- maintaining both properties.
 */
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int>::iterator m = nums.begin() + 1;
        for(int i = 0; i < nums.size(); ++i){
            // find the smallest element in S that is not smaller that nums[i]
            auto it = lower_bound(nums.begin(), m, nums[i]);
            *it = nums[i];
            if(it == m) ++m; 
        }
        return m - nums.begin();
    }
};
