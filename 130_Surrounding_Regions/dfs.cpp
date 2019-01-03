class Solution {
private:
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void recursive(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited){
        int m = board.size(), n = board[0].size();
        visited[row][col] = true;
    
        for(auto d : directions){
            int n_row = row + d[0];
            int n_col = col + d[1];
            if(n_row >= 0 && n_row < m && n_col >= 0 && n_col < n && !visited[n_row][n_col] && board[n_row][n_col] == 'O'){
                recursive(n_row, n_col, board, visited);
            }
        }
    
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        if(!m) return;
        int n = board[0].size();
        
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        // dfs traverse starting from the boarder
        for(int i = 0; i < m; ++i){
            if(board[i][0] == 'O' && !visited[i][0]){
                recursive(i, 0, board, visited);
            }
            if(board[i][n-1] == 'O' && !visited[i][n-1]){
                recursive(i, n-1, board, visited);
            }
           
        }
        
        for(int j = 0; j < n; ++j){
            if(board[0][j] == 'O' && !visited[0][j]){
                recursive(0, j, board, visited);
            } 
            if(board[m-1][j] == 'O' && !visited[m-1][j]){
                recursive(m-1, j, board, visited);
            } 
        }
        
        // flip the points that are not visited from the boarder
        for(int i = 0; i < m ; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
