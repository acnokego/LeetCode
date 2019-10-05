class Solution {
private:
    vector<vector<int>>directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    /*
     * Complexity: O(n*n)
     * Space: O(n*n) // in_queue, O(n) for queue
     */
    int maxDistance(vector<vector<int>>& grid) {
        int row_num = grid.size();
        int col_num = grid[0].size();
        vector<vector<bool>>in_queue(row_num, vector<bool>(col_num, false));
        queue<pair<int, int>>q1, q2;
        
        for(int i = 0; i < row_num; ++i){
            for(int j = 0; j < col_num; ++j){
                if(grid[i][j] == 1){
                    for(auto d : directions){
                        int n_row = i + d[0];
                        int n_col = j + d[1];
                        if(n_row >= 0 && n_row < row_num && n_col >= 0 && n_col < col_num && grid[n_row][n_col] == 0 && !in_queue[n_row][n_col]){
                            q1.push(make_pair(n_row, n_col));
                            in_queue[n_row][n_col] = true;
                        }
                    }
                }
            }
        }
        int dist = 0;
        while(!q1.empty()){
            // there is a new level of nodes
            //cout << q1.size() << endl;
            ++dist;
            while(!q1.empty()){
                auto cell = q1.front();
                int i = cell.first, j = cell.second;
                q1.pop();
                for(auto d : directions){
                    int n_row = i + d[0];
                    int n_col = j + d[1];
                    if(n_row >= 0 && n_row < row_num && n_col >= 0 && n_col < col_num && grid[n_row][n_col] == 0 && !in_queue[n_row][n_col]){
                        q2.push(make_pair(n_row, n_col));
                        in_queue[n_row][n_col] = true;
                    }
                }
            }
            // next step
            swap(q1, q2);
        }
        
        return dist == 0 ? -1 : dist;    
    }
    
};
