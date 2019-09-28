class Solution {
public:
    /*
     * Complexity: O(sum)
     * Space: O(1)
     */
    int splitArray(vector<int>& nums, int m) {
        long sum = 0; 
        int max_n = INT_MIN;
        for(int n : nums){
            sum += n;
            max_n = max(n, max_n);
        }
        long start = max_n, end = sum;
        // binary search to find the minimum capacity
        while(start < end) {
            long mid = (end - start) / 2 + start;
            int num_arrays = 1;
            long total = 0; 
            bool not_fit = false;
            for(int n : nums){
                total += n;
                if(total > mid){
                    total = n;
                    ++num_arrays;
                }
            }    
            // the capacity is too large -> number of subarray smaller
           if (num_arrays < m){
                end = mid - 1;
            } else if (num_arrays == m) {
                end = mid;
            } else {
                start = mid + 1;
           }
        }
        return start;
    }
};
