class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]); // swap it to the position based on its value
            }
        }
        
        // if the element is not matched to the index.
        // return it
        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        
        return 1 + n;
    }
};
