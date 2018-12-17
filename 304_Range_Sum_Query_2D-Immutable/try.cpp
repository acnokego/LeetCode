class NumMatrix {
  /*
   * Complexity: O(mn) for constructor, O(col2 - col1) for sum
   * Space: O(mn)
   */
private:
    vector<vector<int>>row_sum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if(m){
            int n = matrix[0].size();
            row_sum = vector<vector<int>>(m, vector<int>(n));
        
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(j == 0) row_sum[i][j] = matrix[i][j];
                    else{
                        row_sum[i][j] = row_sum[i][j-1] + matrix[i][j];
                    }
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; ++i){
            ans += ((col1 != 0) ? (row_sum[i][col2] - row_sum[i][col1-1]) : row_sum[i][col2]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
