class Solution {
  /*
   * Complexity: O(2^n)
   * Space: O(n)
   */
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subs;
        vector<int>sub;
        genSubsets(nums, 0, sub, subs);
        return subs;
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs){
        // push one combination
        subs.push_back(sub);
        int n = nums.size();
        // for elements after start, try each combinations
        for(int i = start; i < n; ++i){
            // take this element
            sub.push_back(nums[i]);
            genSubsets(nums, i+1, sub, subs);
            // don't take this element 
            sub.pop_back();
        }
    }
};
