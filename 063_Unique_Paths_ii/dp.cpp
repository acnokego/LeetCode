class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(mn)
   */
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m){
            int n = obstacleGrid[0].size();
            vector<vector<int>>dp(m, vector<int>(n));
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(i == 0 && j == 0 && !obstacleGrid[i][j]) dp[i][j] = 1;
                    else if(obstacleGrid[i][j] == 1) continue;
                    else{
                        int up = (i-1) >= 0 ? dp[i-1][j] : 0;
                        int left = (j-1) >= 0 ? dp[i][j-1] : 0;
                        dp[i][j] = up + left;
                    }
                }
            }
            return dp[m-1][n-1];
        }
        
    }
};
