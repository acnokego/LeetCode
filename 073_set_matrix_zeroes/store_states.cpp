class Solution {
  /*
   * Complexity: O(mn)
   * Space: O(1)
   *
   * Using the first element of each row to store the state of each row, and so
   * as the first element of each column. When the row, col are both 0, the same
   * cell is occupied, so we use col0 to store the state of col0.
   * reference: https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
   */
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        int col0 = 1;
        // store state at the first element
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        // iterate from back in order not to overwrite the first element.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};
