class Solution {
  /*
   * Complexity: O(lgn)
   * Space: O(1)
   */
public:

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0) return -1;
        int start = 0, end = n - 1;
        // find the min
        while(start < end){
            int mid = (start + end) / 2;
            // the min is at the right
            if(nums[mid] > nums[end]) start = mid + 1;
            // should consider mid
            else end = mid;
        }
        // start == end
        int min = end;
        // let it be the index of original sorted array
        start = 0;
        end = n - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            // get the index of original sorted array
            int mid_real = (mid + min) % n;
            if(nums[mid_real] == target) return mid_real;
            else if(nums[mid_real] < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
};
