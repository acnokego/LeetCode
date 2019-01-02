class Solution {
  /*
   * Complexity: O(n^k)
   * Space: O(n^k)
   */
public:
    void recursive(vector<vector<int>>& ans, vector<int>& combination, int start, int n, int k){
        if(combination.size() == k){
            ans.push_back(combination);
            return;
        }
        
        for(int i = start; i <= n; ++i){
            combination.push_back(i);
            recursive(ans, combination, i + 1, n, k);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>combination;
        recursive(ans, combination, 1, n, k);
        return ans;
    }
};
