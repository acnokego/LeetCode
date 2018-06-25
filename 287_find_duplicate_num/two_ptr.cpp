class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int fast = nums[nums[0]];
        int slow = nums[0];
        while(fast != slow){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
