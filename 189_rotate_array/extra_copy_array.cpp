class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>copied(nums);
        for(int i = 0; i<nums.size(); ++i){
            int idx = (i < (k % nums.size()) ? nums.size()- (k % nums.size() - i) : i - (k % nums.size()));
            nums[i] = copied[idx];
        }
    }
};
