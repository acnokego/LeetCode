class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(1)
   * Using the second bit to store the update value, and then replace the old
   * bits with new bits by shifting all the values to the right.
   */
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int neightbor = 0;
                for(int I = max(i-1, 0); I < min(m, i+2); ++I){
                    for(int J = max(j-1, 0); J < min(n, j+2); ++J){
                        // only check the old bit
                        if(I != i || J != j) neightbor += (board[I][J] & 1);
                    }
                }
                // only update the second bit
                if((neightbor == 2 && (board[i][j] & 1)) || neightbor == 3)
                    board[i][j] |= 2;
            }
        }
        // replace the old bit with updated bit
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] >>= 1;
            }
        }
    }
};
