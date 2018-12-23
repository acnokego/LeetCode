class Solution {
  /*
   * Complexity: O(lgn)
   * Space: O(1)
   */
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        
        while(start < end){
            int mid = (end - start) / 2 + start;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        
        // Generally, if the target doesn't exist, we would possibly have
        // nums[start] < target < [end] or target < nums[start] or target > nums[end]
        // (start , end) are the value before start == end.
        // start == end
        if(nums[start] < target) return start + 1;
        else return start;
        
    }
};
