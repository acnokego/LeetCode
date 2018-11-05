class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(1)
   */
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int s = nums.size();
        vector<int>ans;
        if(s){
            // for each element in nums
            for(int i = 0; i < s; ++i){
                bool found = false;
                for(int j = (i+1); j < (i + s); ++j){
                    if(nums[j % s] > nums[i]){
                        ans.push_back(nums[j % s]);
                        found = true;
                        break;
                    }
                }
                if(!found) ans.push_back(-1);
            }
            
        }
        return ans;
    }
};
