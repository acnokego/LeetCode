class Solution {
  /*
   * Complexity: O(lgn)
   * Space: O(1)
   */
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = (start + end) / 2;
            int mid2 = mid + 1;
            // if the mid2 bigger
            // there must be a peak starting mid2
            // or motonically increasing(the last index is peak)
            if(nums[mid] < nums[mid2]){
                start = mid2;
            }
            // mid is bigger 
            // there must be a peak 
            // or motonically decreasing (first index is peak)
            else {
                end = mid;
            }
        }
        return start;
        
    }
};
