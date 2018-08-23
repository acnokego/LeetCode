class Solution {
  /*
   * Complexity: O(2^n)
   * if there is duplicate elements the complexity would be like:
   * https://leetcode.com/problems/subsets-ii/discuss/30168/C++-solution-and-explanation?page=3
   * Space: O(n)
   */
public:
    void recursive(vector<vector<int>>& ans, vector<int>& subset, int start, vector<int>& nums){
        ans.push_back(subset);
        if(start > (nums.size() - 1)) return;
        for(int i = start; i < nums.size(); ++i){
            // the same value that has been taken into consideration before (i > start)
            if(i > start && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            recursive(ans, subset, i+1, nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        if(!nums.size()) return ans;
        sort(nums.begin(), nums.end());
        vector<int>subset;
        recursive(ans, subset, 0, nums);
        return ans;
    }
};
