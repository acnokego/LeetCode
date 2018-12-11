class Solution {
  /*
   * Complexity: O(nlgn)
   * Space: O(n)
   */
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>copy(nums.begin(), nums.end());
        sort(copy.begin(), copy.end());
        int n = nums.size();
        int start = -1, end = -1;
        
        for(int i = 0; i < n; ++i){
            if(copy[i] != nums[i]){
                if(start < 0) start = i;
                end = i;
            }
        }
        
        return (start < 0) ? 0 : (end - start + 1);
    }
};
