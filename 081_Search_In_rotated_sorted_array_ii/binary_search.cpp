class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(!nums.size()) return false;
        int start = 0, end = nums.size() - 1;
        while(start < end){
            int mid = (end - start) / 2 + start;
            if(nums[mid] == target) return true;
            if(nums[start] == nums[mid] && nums[end] == nums[mid]){ // check if first half order
                ++start;
                --end;
            } else if(nums[start] <= nums[mid]){ // first half order
                if(nums[start] <= target && nums[mid] > target) end = mid -1;
                else start = mid + 1;
            } else { // first half out of order
                if(nums[mid] < target && nums[end] >= target) start = mid + 1;
                else end = mid - 1;
            }
            
        }
        return nums[start] == target;
    }
};
