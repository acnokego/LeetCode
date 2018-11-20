class Solution {
  /*
   * Complexity: O(2^n)
   * Space: O(n)
   */
public:
    void recursive(vector<int>& nums, int start, vector<int>& tmp, vector<int>& ans){ 
        if(tmp.size() > ans.size()){
            ans = tmp;
        }
        for(int i = start; i < nums.size(); ++i){
            if(tmp.size() && nums[i] % tmp.back() != 0) continue;
            tmp.push_back(nums[i]);
            recursive(nums, i + 1, tmp, ans);
            tmp.pop_back();
            if(ans.size() > nums.size()/2) return;
        }

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        vector<int>tmp;
        recursive(nums, 0, tmp, ans);
        return ans;
    }
};
