class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(mn)
   */
public:
    int checkLife(vector<vector<int>> & board, int row, int col){
        int neightbor = 0;
        int m = board.size();
        int n = board[0].size();
        for(int i = -1; i < 2; ++i){
            for(int j = -1; j < 2; ++j){
                if((row + i >= 0) && (row + i < m) && (col + j >= 0) && (col + j < n)){
                    if((i!= 0 || j != 0) && board[row+i][col+j] == 1) neightbor += 1;
                }
            }
        }
        // rules
        if(board[row][col]){
            if(neightbor < 2) return 0;
            else if(neightbor <= 3) return 1;
            else return 0;
        }
        else{
            if(neightbor == 3) return 1;
            else return 0;
        }
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;
        vector< vector<int> >tmp(m, vector<int>(n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                tmp[i][j] += checkLife(board, i, j);
        }
        board = tmp;
    }
};
