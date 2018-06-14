class Solution {
public:
    void reversed(int start, int end, vector<int>& nums){
        int length = end - start + 1;
        int middle = length / 2;
        int tmp;
        for(int i = 0; i< middle; ++i){
            tmp = nums[start + i];
            nums[start + i] = nums[end-i];
            nums[end - i] = tmp;
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reversed(0, nums.size()-1, nums);
        reversed(0, k-1, nums);
        reversed(k, nums.size()-1, nums);
    }
};
