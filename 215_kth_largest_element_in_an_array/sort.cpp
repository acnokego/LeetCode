class Solution {
  /*
   * Complexity : O(nlgn)
   * Space: O(1)
   */
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) return NULL;
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};
