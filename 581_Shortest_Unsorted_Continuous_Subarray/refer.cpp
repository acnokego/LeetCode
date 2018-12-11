class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -1;
        int t_min = nums[n - 1], t_max = nums[0];
        
        for(int i = 1; i < n; ++i){
            // find the index that is in the wrong order
            // nums[i] should be the max
            t_max = max(nums[i], t_max);
            // nums[n - i - 1] should be the min when traverse from the back
            t_min = min(nums[n - i - 1], t_min);
            if(nums[i] < t_max) end = i;
            if(nums[n-i-1] > t_min) start = n - i - 1;
        }
        
        return (start < 0) ? 0 : (end - start + 1);
    }
};
