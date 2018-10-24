class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int s = nums.size();
        vector<string>ans;
        if(s){
          int start = nums[0], end;
          string range = to_string(start);
          for(int i = 1; i < s; ++i){
              if(nums[i] != nums[i-1] + 1){
                  end = nums[i-1];
                  if(end != start){
                      range += ("->" + to_string(end));
                  }
                  ans.push_back(range);
                  start = nums[i];
                  range = to_string(start);
              }
              else if(i == nums.size() - 1){
                  end = nums[i];
                   if(end != start){
                      range += ("->" + to_string(end));
                  }
              }
          }
          ans.push_back(range);
        }
        return ans;
    }
};
