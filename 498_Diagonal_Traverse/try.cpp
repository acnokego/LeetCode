class Solution {
  /*
   * Complexity: O(m*n)
   * Space: O(1)
   */
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size();
        if(!m) return ans;
        int n = matrix[0].size();
        if(!n) return ans;
        
        int i = 0, j = 0;
        bool up = true;
        int total_num = m*n;
        while(ans.size() < total_num){
            ans.push_back(matrix[i][j]);
            if(up){
                int i_n = (i - 1 >= 0 && j + 1 <= n - 1) ? (i - 1) : (j + 1 <= n - 1) ? i : i+1;
                int j_n = (i - 1 >= 0 && j + 1 <= n - 1) ? (j + 1) : (j + 1 <= n - 1) ? j + 1 : j;
                up = (i - 1 < 0 || j + 1 > n - 1) ? false : true;
                i = i_n; j = j_n;
            }
            else{
                int i_n = (i + 1 <= m - 1 && j - 1 >= 0) ? (i + 1) : (j - 1 >= 0) ? i : (i + 1 <= m - 1) ? i + 1: i;
                int j_n = (i + 1 <= m - 1 && j - 1 >= 0) ? (j - 1) : (j - 1 >= 0) ? j+1 : (i + 1 <= m - 1)? j : j + 1;
                up = (i + 1 > m - 1 || j - 1 < 0) ? true : false;
                i = i_n; j = j_n;
            }
        }       
        return ans;
    }
};
