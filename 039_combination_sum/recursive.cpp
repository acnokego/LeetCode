class Solution {
  /*
   * Complexity: O(2^#candidates*target)
   * Space: O(target)
   */
public:
    void recursive(vector<vector<int>>& ans, vector<int>& combinations, int start, int target, vector<int>& nums){
        if(target == 0){
            ans.push_back(combinations);
            return;
        }
        if(start > nums.size() - 1 || target < 0) return;
        for(int i = start; i < nums.size(); ++i){
            if(target - nums[i] >= 0){
                combinations.push_back(nums[i]);
                // can reuse the element
                recursive(ans, combinations, i, target - nums[i], nums);
                combinations.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        if(!candidates.size())return ans;
        vector<int>combinations;
        recursive(ans, combinations, 0, target, candidates);
        return ans;
    }
};
