class Solution {
public:
    /*
     * Complexity: O(lgn)
     * Space: O(1)
     */
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        //*** the number of elements in nums[:start] should be even
        int start = 0, end = n - 1;
        
        while(start < end) {
            int mid = (end - start) / 2 + start;
            
            if(mid % 2 == 0){
                // mid is even
                // the number of elements in nums[start:mid] is even
                if(nums[mid] == nums[mid+1]){
                    // the single element have to be in nums[mid+2:]
                    start = mid + 2;
                } else {
                    end = mid;
                }
            } else {
                // mid is odd
                // the number of elements in nums[start:mid] is odd
                if(nums[mid] == nums[mid-1]){
                    // the single element have be in nums[mid+1:]
                    // since the number of elemens in nums[mid+1:] is odd
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
            
        }
        return nums[start];
        
    }
};
