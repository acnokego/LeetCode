class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(mn)
   */
private:
    vector<vector<int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    void dfs(vector<vector<int>> & grid, int i, int j, int& ans, vector<vector<bool>>& visited
            ,vector<vector<int>> & neighbor){
        visited[i][j] = true;
        for(auto& d: directions){
            int i_n = i + d[0];
            int j_n = j + d[1];
            if(i_n >= 0 && i_n < grid.size() && j_n >= 0 && j_n < grid[0].size()){
                neighbor[i_n][j_n] += 1;
            }
        }
        for(auto & d: directions){
            int i_n = i + d[0];
            int j_n = j + d[1];
            if(i_n >= 0 && i_n < grid.size() && j_n >= 0 && j_n < grid[0].size()
                 && grid[i_n][j_n] && !visited[i_n][j_n]){
                    switch(neighbor[i_n][j_n]){
                        case 1:
                            ans += 2;
                            break;
                        case 2:
                            break;
                        case 3:
                            ans -= 2;
                            break;
                        case 4:
                            ans -= 4;
                            break;
                        default:
                            break;
                    }
                    dfs(grid, i_n, j_n, ans, visited, neighbor);
                
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size();
        if(m){
            int n = grid[0].size();
            vector<vector<bool>> visited (m, vector<bool>(n));
            vector<vector<int>> neighbor(m, vector<int>(n));
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(grid[i][j] && !visited[i][j]){
                        // start of the island
                        ans += 4;
                        dfs(grid, i, j, ans, visited, neighbor);
                    }
                }
            }
        }
        return ans;
    }
};
