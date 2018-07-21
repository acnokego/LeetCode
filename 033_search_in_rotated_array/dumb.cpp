class Solution {
  /*
   * Complexity: worst-case O(n), if we choose the correct side ( the target is
   * in the correct order with the mid, then it is O(lgn)
   * Space: O(n)
   */
public:
    int binary_search(vector<int>& nums, int start, int end, int target){
        if(start > end) return -1;
        if(start == end){
            if(nums[start] == target) return start;
            else return -1;
        }
        int mid = (end - start + 1) / 2;
        if(target == nums[start + mid]) return start + mid;
        else if(target < nums[mid]){
            int left = binary_search(nums, start, start + mid - 1, target);
            if(left >= 0) return left;
            else return binary_search(nums, start + mid + 1, end, target); 
        }
        else{
            int right = binary_search(nums, start + mid + 1, end, target);
            if(right >= 0) return right;
            else return binary_search(nums, start, start + mid - 1, target); 
        }
        
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0) return -1;
        int start = 0, end = n - 1;
        return binary_search(nums, start, end, target);
    }
};
