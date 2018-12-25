class Solution {
  /*
   * Complexity: O(lg(min(m,n));
   * Space: O(1);
   */
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // separate nums1 into nums1[0...i-1], nums1[i...m-1]
        // separate nums2 into nums2[0...j-1], nums2[j...n-1]
        // we want 
        // 1. the number of elements in (nums1[0...i-1], nums2[0...j-1]) == (nums1[i...m-1], nums2[j...n-1])
        // 2. the nums1[i] >= nums[j-1] && nums[i-1] <= nums2[j]
        // n should be bigger than m
        if(m > n){
            nums1.swap(nums2);
            swap(m, n);
        }
        // for condition 1: i+j == m - i + n - j (+1 if m+n is odd)-> 
        // we are going to search i using the second condition
        // j = (m - 2i + n)/2 = (m+n)/2 - i (n > m or j would < 0)
        // if m+n is odd the left part would have one more element
        // so we could return the max_left directly when m+n is odd
        int i_min = 0, i_max = m, half_len = (m + n + 1) / 2; // m + n + 1 / 2 if it is even it would ignore 1.

        // binary search
        while(i_min <= i_max){
            int i = (i_min + i_max) / 2;
            int j = half_len - i;
            // by increasing i, nums1[i] would be bigger, nums2[j-1] would be smaller
            if(i < m && nums2[j-1] > nums1[i]) i_min = i + 1;
            // by decreasing i, nums1[i] would be smaller, and nums2[j] would be bigger
            else if(i > 0 && nums1[i-1] > nums2[j]) i_max = i - 1;
            // i is correct
            // all the conditions is meet
            else{
                // solve corner case
                int max_left = (i == 0) ? nums2[j-1] : (j == 0) ? nums1[i-1] : max(nums1[i - 1], nums2[j - 1]);
                int min_right = (i == m) ? nums2[j] : (j == n) ? nums1[i] : min(nums1[i], nums2[j]);
                if((m + n) % 2 == 1) return max_left;
                else return (max_left + min_right) / 2.0;
            }
        }
        return 0;
    }
};
