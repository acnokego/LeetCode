class Solution {
  /*
   * Complexity: O(n!)
   * Space: O(n) stack, size of nums
   */
public:
    void recursive(vector<vector<int>>&ans, vector<int>& permutation, vector<bool>& used, vector<int>& nums){
        if(permutation.size() == nums.size()){
            ans.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            // the possible of permutation start with the same i has been counted before
            if(used[i] || ((i > 0 && nums[i] == nums[i-1]) && !used[i-1])) continue;
            else{
                used[i] = true;
                permutation.push_back(nums[i]);
                recursive(ans, permutation, used, nums);
                used[i] = false;
                permutation.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        if(!nums.size()) return ans;
        // need to be sorted before looking for permutations.
        sort(nums.begin(), nums.end());
        vector<int>permutation;
        vector<bool>used(nums.size(), 0);
        recursive(ans, permutation, used, nums);
        return ans;
    }
};
