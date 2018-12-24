class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(mn)
   */
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int ans = 0;
        if(m){
            int n = matrix[0].size();
            // find the maximum length of square that has bottom-left corner at (i, j)
            vector<vector<int>>dp(m, vector<int>(n));
           
            
            // base 
            for(int col = 0; col < n; ++col){
                dp[0][col] = matrix[0][col] - '0';
                ans = max(ans, dp[0][col]);
            }
            for(int row = 0; row < m; ++row){
                dp[row][0] = matrix[row][0] - '0';
                ans = max(ans, dp[row][0]);
            }
            
            // dp
            // to have square with longer length
            // if (i, j) == 1, find the min length of dp[i-1][j-1] dp[i][j-1] , dp[i-1][j]
            // and add 1.
            for(int i = 1; i < m; ++i){
                for(int j = 1; j < n; ++j){
                    if(matrix[i][j] == '1'){
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
            
        }
        return ans*ans;
    }
};
