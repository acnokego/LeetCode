class Solution {
  /*
   * Complexity: O(m+n)
   * Space: O(1)
   */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        if(!n) return false;
        for(int row = 0; row < m; ++row){
            if(matrix[row][n-1] > target){
                for(int col = 0; col < n; ++col){
                    if(matrix[row][col] == target) return true;
                }
                return false;
            }
            else if(matrix[row][n-1] == target) return true;
        }
        return false;
    }
};
