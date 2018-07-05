class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n) Only the space for ans;
   * using p_left, p_right  to store the product of elements from the left,
   * right respectively. and multiply ans[a] with the products at the left of a
   * first. When the n-i-1 arrives the previous index a, we multiple the p_right
   * then.
   */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1);
        int p_right = 1;
        int p_left = 1;
        for(int i = 0; i < n; ++i){
            ans[i] *= p_left;
            p_left *= nums[i];
            ans[n-i-1] *= p_right;
            p_right *= nums[n-i-1];
        }
        return ans;
    }
};
