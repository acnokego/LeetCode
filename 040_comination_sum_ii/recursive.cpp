class Solution {
public:
    void recursive(vector<vector<int>>& ans, vector<int>& combinations, int start, int target, vector<int>& nums, vector<bool>& used){
        // like subsets ii, but need to check the target
        if(target == 0){
            ans.push_back(combinations);
            return;
        }
        if(start > nums.size() - 1 || target < 0) return;
        for(int i = start; i < nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1]) continue;
            if(target - nums[i] >= 0){
                combinations.push_back(nums[i]);
                recursive(ans, combinations, i+1, target - nums[i], nums, used);
                combinations.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        if(!candidates.size())return ans;
        sort(candidates.begin(), candidates.end());
        vector<int>combinations;
        vector<bool>used(target, 0);
        recursive(ans, combinations, 0, target, candidates, used);
        return ans;
    }
};
