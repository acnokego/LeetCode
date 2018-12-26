class Solution {
  /*
   * Complexity: O(n!)
   * Space: O(n)
   */
public:
    void recursive(vector<vector<string>>& ans, int n, vector<string>& sol, vector<bool>& col_flag, vector<bool>& flag_45, vector<bool>& flag_135 ){
        if(sol.size() == n){
            ans.push_back(sol);
            return;
        }
        for(int i = 0; i < n; ++i){
            vector<bool> tmp_prev;
            if(!col_flag[i] && !flag_45[sol.size() + i] && !flag_135[n - 1 + i - sol.size()]){
                string curr_row = "";
                for(int j = 0; j < n; ++j){
                    if(j == i) curr_row += 'Q';
                    else curr_row += '.';
                }
                col_flag[i] = true;
                flag_45[sol.size() + i] = true;
                flag_135[n - 1 + i - sol.size()] = true;
                sol.push_back(curr_row);
                
                recursive(ans, n, sol, col_flag, flag_45, flag_135);
                
                sol.pop_back();
                col_flag[i] = false;
                flag_45[sol.size() + i] = false;
                flag_135[n - 1 + i - sol.size()] = false;
            }
        }
        return;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        if(!n) return ans;
        
        vector<bool>col_flag(n, false);
        vector<bool>flag_45(2*n - 1, false); // bit mask of whether each of 45 degree diagonals is used
        vector<bool>flag_135(2*n - 1, false); // bit mask of whether each of 135 degree diagonals is used
        vector<string>row;
        recursive(ans, n, row, col_flag, flag_45, flag_135);
        
        return ans;
        
    }
};
