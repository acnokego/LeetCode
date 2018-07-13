class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = 1;
        // put all elements into a set.
        unordered_set<int>occur(nums.begin(), nums.end());
        for(int n: nums){
            int tmp_ans = 1;
            int base_num = n;
            // only check the start of each streak
            if(occur.find(n-1) == occur.end()){
                // then calculate its length
                while(occur.find(base_num + 1) != occur.end()){
                    ++tmp_ans;
                    ++base_num;
                }
                if(tmp_ans > ans) ans = tmp_ans;
            }
        }
        return ans;
    }
};
