class Solution {
  /*
   * Complexity: O(n*s)
   * Space: O(n)
   */
public:
    int recursive(vector<int>&nums, int idx, int target, unordered_map<string, int>& mem){
        string p = to_string(idx) + "->" + to_string(target);
        if(mem.count(p)){
            return mem[p];
        }
        if(idx == nums.size()){
            return target == 0;
        }
        
        mem[p] = recursive(nums, idx + 1, target - nums[idx], mem) +
            recursive(nums, idx + 1, target + nums[idx], mem);
        return mem[p];
        
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        unordered_map<string, int>mem;
        return recursive(nums, 0, S, mem);
    }
};
