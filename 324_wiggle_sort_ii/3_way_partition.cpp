class Solution {
  /*
   * Complexity: O(n) Avg, worst O(n^2) // find nth_element alg.
   * Space: O(1)
   * Reference:
   * https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)+O(1)-after-median-Virtual-Indexing?page=1
   */
public:
    int partition(vector<int>& nums, int start, int end){
        int p_idx = rand() % (end - start + 1);
        swap(nums[start + p_idx], nums[end]);
        int pivot = nums[end];
        int i = start, j = start;
        for(; j < end ; ++j){
            if(nums[j] < pivot){
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[end], nums[i]);
        return i;
    }
    void find_mid(vector<int>& nums){
        int s = nums.size();
        int mid = (s / 2);
        int start = 0;
        int end = s - 1;
        while(start < end){
            int idx = partition(nums, start, end);
            if(idx == mid) break;
            else if (idx < mid) start = idx + 1;
            else end = idx - 1;
        }
        
    }
    void wiggleSort(vector<int>& nums) {
        // move the element < nums[s/2] to the first half
        // can be replaced with nth_element function
        find_mid(nums);
        int s = nums.size();
        int mid = nums[(s/2)];
        /*index mapping 
         * ex. 10 elements, 
         * A(0) -> nums[1], A(1) -> nums[3], A(2) -> nums[5]...
         * A(5) -> nums[0], A(6) -> nums[2], A(7) -> nums[4]...
         *if s is even, then the divisor should plus one 
         *(the last odd number is n-1, and the next odd number would be n+1. 
         *but we want the index point to 0 -> the divisor should be n + 1)
         */
        #define A(i) nums[(1+2*i) % (s | 1)]
        /* three-way partition. move elements smaller than mid to odd (the first
         * 1/3 of A(i)), move the element bigger than mid to even(the last 1/3). 
         * elements equal to mid to the middle 1/3 A(i).
         */
        int i = 0, j = 0, k = s-1;
        while(j <= k){
            // at the odd indexes
            if(A(j) > mid) swap(A(i++), A(j++));
            // at the even indexes
            else if (A(j) < mid) swap(A(j), A(k--));
            // at the last odd idx/ middle pos (if size is even), else if 
            // size is odd, the mid would be in the first even 
            // /middle pos.
            else ++j;
        }
        
    }
};
