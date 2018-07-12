class Solution {
  /*
   * Complexity: O(n), worst-case O(n^2): if only partition one element each
   * time. randomly choosing the pivot can decrease the opportunity that the
   * worst case happens.
   * Space: O(1);
   */
public:
    void swap(vector<int>& nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    // the partition alg in quicksort, move the elements that are bigger than
    // pivot to the section [0, i-1]
    int partition(vector<int>& nums, int start, int end){
        // randomly choose pivot
        int pivot_idx = rand() % (end - start + 1); 
        swap(nums, start + pivot_idx, end);
        int pivot = nums[end], i = start;
        for(int j = start; j < end; ++j){
            if(nums[j] >= pivot){
                swap(nums, i, j);
                ++i;
            }
        }
        swap(nums, i, end);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        int idx;
        while(start <= end){
            idx = partition(nums, start, end);
            if(idx == k-1) return nums[idx];
            // try [start ... idx-1]
            else if (idx > k-1){
                end = idx-1;
            }
            // try [idx + 1 ... end]
            else start = idx + 1;          
        }
        // if k is more than the nums.size()
        return NULL;
    }
};
