class Solution {
  /*
   * Complexity: O(m*n)
   * Space: O(m*n)
   */
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m){
            int n = grid[0].size();
            vector<vector<int>>dp(m, vector<int>(n, -1));
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                    else{
                        int up = (i - 1) >= 0 ? dp[i-1][j] : -1;
                        int left = (j - 1) >= 0 ? dp[i][j-1] : -1;
                        int small = (up >= 0 && left >= 0) ? ((up < left) ? up : left) : ((up < 0) ? left : up);
                        dp[i][j] = small + grid[i][j];
                    }
                }
            }
            return dp[m-1][n-1];
        }
        
    }
};
