class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastZero = -1;
        int tmp;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0 && lastZero < 0) lastZero = i;
            else if(nums[i] != 0 && lastZero >= 0 ){
                tmp = nums[i];
                nums[i] = 0;
                nums[lastZero] = tmp;
                lastZero += 1;
            }
            else continue;
        }      
    }
};
