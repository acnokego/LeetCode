class Solution {
  /*
   * Complexity: O(n) // total nodes
   * Space: O(row)
   */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int>dp(row, INT_MAX);
        
        for(int i = 0; i < row; ++i){
            for(int j = triangle[i].size()-1; j >= 0; --j){
                if(i == 0 && j == 0){
                    dp[j] = triangle[i][j];
                    continue;
                }
                dp[j] = triangle[i][j] + min(dp[j], ((j - 1) >= 0 ? dp[j-1] : INT_MAX));
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
