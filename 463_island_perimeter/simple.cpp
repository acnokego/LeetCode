class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(1)
   */
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size();
        if(m){
            int n = grid[0].size();
            int islands = 0, neighbors = 0;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(grid[i][j] == 1){
                        ++islands;
                        if(i + 1 < m && grid[i+1][j]) ++neighbors;
                        if(j + 1 < n && grid[i][j+1]) ++neighbors;
                    }
                }
            }
            ans = 4*islands-2*neighbors;
        }
        return ans;
    }
};
