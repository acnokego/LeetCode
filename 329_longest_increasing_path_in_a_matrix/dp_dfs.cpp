class Solution {
  /*
   * Complexity: O(mn) (dp)
   * Space: O(mn)
   */
private:
    const vector<vector<int>>direction{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(dp[i][j] != 0) return dp[i][j];
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1;
        int tmp;
        for(int d = 0; d < 4; ++d){
            int x = i + direction[d][0];
            int y = j + direction[d][1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]){
                tmp = 1 + dfs(matrix, x, y, dp);
                if(tmp > ans) ans = tmp;
            }
        }
        dp[i][j] = ans;
        return ans;       
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        // (length, max number in path)
        vector<vector<int>>dp(m, vector<int>(n));
        int ans = 1;
        int tmp;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                tmp = dfs(matrix, i, j, dp);
                if(tmp > ans) ans = tmp;
            }
        }
        return ans;   
    }
};
