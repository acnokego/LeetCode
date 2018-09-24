class Solution {
  /*
   * Complexity: O(m+n)
   * Space: O(1)
   */
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr_1 = m - 1, ptr_2 = n - 1, all = m+n-1;
        while(ptr_2 >= 0 && ptr_1 >= 0){
            nums1[all--] = (nums2[ptr_2] > nums1[ptr_1]) ? nums2[ptr_2--] : nums1[ptr_1--]; 
        }
    }
};
