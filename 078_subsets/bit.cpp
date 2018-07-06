class Solution {
  /*
   * Complexity: O(2^n*n)
   * Space: O(1) no extra space
   * For each possible combinations (bit array), we check each element that if 
   * we have to push it into ans by checking the specific bit is 1 or 0
   *
   * There are still other solutions (recursive, iterative):
   * https://leetcode.com/problems/subsets/discuss/27278/C++-RecursiveIterativeBit-Manipulation-Solutions-with-Explanations
   */
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int set_n = pow(2, n);
        vector< vector<int> > ans(set_n, vector<int>());    
        for(int i = 0; i < pow(2, n); ++i){
            for(int j = 0; j < n; ++j){
                if((i >> j) & 1) ans[i].push_back(nums[j]);
            }
        }
        return ans;
    }
};
