class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(m + n)
   */
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        vector<bool>zero_row(m);
        vector<bool>zero_col(n);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    zero_row[i] = 1;
                    zero_col[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            if(zero_row[i]) matrix[i] = vector<int>(n, 0);
            else{
                for(int j = 0; j < n; ++j){
                    if(zero_col[j]) matrix[i][j] = 0;
                }
            }
        } 
    }
};
