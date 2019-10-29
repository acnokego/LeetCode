class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(1)
     */
    int jump(vector<int>& nums) {
        int jump = 0, currEnd = 0, furtherest = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            furtherest = max(furtherest, nums[i] + i);
            if(i == currEnd){
                jump += 1;
                currEnd = furtherest;
            }
        }
        return jump;
    }
};
