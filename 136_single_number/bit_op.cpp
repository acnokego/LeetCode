class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   * Since a ^ 0 = a, a ^ a = 0;
   */
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums){
            ans ^= num;
        }
        return ans;
    }
};
