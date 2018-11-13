class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
private:
    vector<vector<int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return matrix;
        int n = matrix[0].size();
        vector<vector<int>>ans(m, vector<int>(n, INT_MAX));
        
        queue<pair<int, int>>q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!matrix[i][j]){
                    q.push(make_pair(i, j));
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(auto & d : directions){
                int n_i = p.first + d[0];
                int n_j = p.second + d[1];
                if(n_i >= 0 && n_i < m && n_j >=0 && n_j < n){
                    if(ans[n_i][n_j] <= (ans[p.first][p.second] + 1)) continue;
                    ans[n_i][n_j] = ans[p.first][p.second] + 1;
                    q.push(make_pair(n_i, n_j));
                }
            }
        }
        return ans;
    }
};
