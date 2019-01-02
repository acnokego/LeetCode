class Solution {
  /*
   * Complexity: O(lg(n))
   * Space: O(1)
   */
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        
        while(start < end){
            int mid = (end - start) / 2 + start;
            if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        
        return nums[start];
    }
};
