class Solution {
  /*
   * Complexity: O(mn) would visit each cell once
   * Space: O(mn)
   *
   * Started from the cell next to the ocean. Use two separate visited vectors
   * for different oceans. Then calulate the AND of two vectors to see the cell
   * can flow to both two oceans.
   */
private:
    vector<vector<int>>directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    void dfs(vector<vector<int>>& matrix, int i, int j,  vector<vector<bool>>& visited) {
        
        visited[i][j] = true;
        for(auto& d : directions){
            int m_n = i + d[0];
            int n_n = j + d[1];
            if(m_n >= 0 && m_n < matrix.size() && n_n >= 0 && n_n < matrix[0].size() 
               && !visited[m_n][n_n] && matrix[m_n][n_n] >= matrix[i][j]){
                dfs(matrix, m_n, n_n, visited);
            }
        }
        return;
    }
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>>ans;
        int m = matrix.size(), n = 0; 
        if(m) n = matrix[0].size();
        if(n){
            vector<vector<bool>>pacific(m, vector<bool>(n));
            vector<vector<bool>>atlantic(m, vector<bool>(n));
            for(int i = 0; i < m; ++i){
                dfs(matrix, i, 0, pacific);
                dfs(matrix, i, n - 1, atlantic);
            }
            for(int i = 0; i < n; ++i){
                dfs(matrix, 0, i, pacific);
                dfs(matrix, m-1, i, atlantic);
            }
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(pacific[i][j] && atlantic[i][j]) ans.push_back(make_pair(i,j));
                }
            }
        }
        return ans;
    }
};
