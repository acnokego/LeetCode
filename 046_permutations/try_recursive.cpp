class Solution {
  /*
   * Complexity: O(n!)
   * Space: O(n!)
   */
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int> > ans;
        if(n == 0 || n == 1){
            ans.push_back(nums);
            return ans;
        }
        for(int i = n-1 ; i >= 0; --i){
            vector< vector<int> > tmp_ans;
            vector<int>tmp(nums.begin(), nums.end());
            // swap nums[i] to the last pos
            int swap = tmp[i];
            tmp[i] = tmp.back();
            // pass the array after removing the last element and get the possible permutations of it
            tmp.erase(tmp.end()-1);
            tmp_ans = permute(tmp);
            int tmp_size = tmp_ans.size();
            // then append the removed element back to the last pos
            for(int j = 0; j < tmp_size; ++j){
                tmp_ans[j].push_back(swap);
            }
            // append the possible permutations which has num[i] as the last element
            ans.insert(ans.end(), tmp_ans.begin(), tmp_ans.end());
        }
        return ans;   
    }
};
