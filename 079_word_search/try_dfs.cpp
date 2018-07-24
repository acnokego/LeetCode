class Solution {
  /*
   * Complexity: O(mn) total number of the elements
   * Space : O(word length) # number of stack + O(n) visited
   * Applyind dfs to see which path is matched to the input string.
   */
private:
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool dfs(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visited, string& word, int word_idx){
        if(word_idx > (word.length() - 1)) return true;
        visited[row][col] = true;
        bool success = false;
        for(auto& d : direction){
            int x = row + d[0];
            int y = col + d[1];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == word[word_idx] && !visited[x][y]){
                success = dfs(board, x, y, visited, word, word_idx + 1);
                if(success) return true;
            }
        }
        visited[row][col] = false;
        return success;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if(row == 0) return false;
        int col = board[0].size();
        if(col == 0) return false;
        vector<vector<bool>>visited(row, vector<bool>(col));
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == word[0]){
                     if(dfs(board, i, j, visited, word, 1)) return true;
                }
            }
        }
        return false;
    }
};
