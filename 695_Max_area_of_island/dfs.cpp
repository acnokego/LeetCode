class Solution {
    /*
     * Complexity: O(n), n: number of elements
     * Space: O(n) 
     */
private:
    const vector<vector<int>>directions = {{0,1}, {1,0}, {0,-1},{-1,0}};
public:
    int dfs(const vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        
        visited[row][col] = true;
        int sum = 1;
        for(auto d : directions) {
            int n_row = row + d[0];
            int n_col = col + d[1];
            if(n_row >= 0 && n_row < grid.size() && n_col >= 0 && n_col < grid[0].size() && grid[n_row][n_col] && !visited[n_row][n_col]) {
                sum += dfs(grid, n_row, n_col, visited);
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row_num = grid.size();
        if(!row_num) return 0;
        int col_num = grid[0].size();
        if(!col_num) return 0;
        
        vector<vector<bool>>visited(row_num, vector<bool>(col_num, false));
        
        int ans = 0;
        for(int i = 0; i < row_num; ++i){
            for(int j = 0; j < col_num; ++j) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int sum = dfs(grid, i, j, visited);
                    ans = (sum > ans) ? sum : ans;
                }
            }
        }
        return ans;
    }
};
