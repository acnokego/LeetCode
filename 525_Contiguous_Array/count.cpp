class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     *
     * reference: https://leetcode.com/problems/contiguous-array/discuss/99655/Python-O(n)-Solution-with-Visual-Explanation
     *
     * If the count occurred before, means the number of 1s and 0s is equal in
     * nums[prev_idx + 1, curr_idx]
     */ 
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int>count_idx;
        
        int max_len = 0;
        int count = 0;
        count_idx[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                --count;
            } else ++count;
            
            if(count_idx.count(count)){
                max_len = max(max_len, i - count_idx[count]);
            } else {
                count_idx[count] = i;
            }
        }
        return max_len;
    }
};
