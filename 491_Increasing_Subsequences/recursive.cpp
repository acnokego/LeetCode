class Solution {
public:
    /*
     * Complexity: O(2^n)
     * Space: O(n)
     */
    void recursive(vector<int>& nums, int start, vector<int>& tmp_seq, vector<vector<int>>& ans){
        if(tmp_seq.size() >= 2){
            ans.push_back(tmp_seq);
        }
        unordered_set<int> visited;
        for(int i = start; i < nums.size(); ++i){   
            if(!visited.count(nums[i]) && (!tmp_seq.size() || (nums[i] >= tmp_seq.back()))){
                // prevent use the same number that used before
                visited.insert(nums[i]);
                tmp_seq.push_back(nums[i]);
                recursive(nums, i + 1, tmp_seq, ans);
                tmp_seq.pop_back();
            }
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>tmp_seq;
        vector<vector<int>>ans;
        recursive(nums, 0, tmp_seq, ans);
        return ans;
    }
};
