class NumArray {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
private:
    vector<int>sum;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        sum = vector<int>(n);
        
        for(int i = 0; i < n; ++i){
            if(i == 0) sum[i] = nums[i];
            else{
                sum[i] = nums[i] + sum[i-1];
            }
        }
        
    }
    
    int sumRange(int i, int j) {
        return (i != 0) ? (sum[j] - sum[i-1]) : sum[j] ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
