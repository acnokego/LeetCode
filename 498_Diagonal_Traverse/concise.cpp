class Solution {
  /*
   * Complexity : O(m*n)
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
        int d = 0;
        vector<vector<int>> dir = {{-1, 1}, {1, -1}};
        int total_num = m*n;
        while(ans.size() < total_num){
            ans.push_back(matrix[i][j]);
            int i_n = i + dir[d][0];
            int j_n = j + dir[d][1];
            
            if(i_n >= m){i_n = m - 1; j_n += 2; d = 1-d;} // bottom border
            if(j_n >= n){j_n = n - 1; i_n += 2; d = 1-d;} // right border
            if(i_n < 0){i_n = 0; d = 1 - d;} // top
            if(j_n < 0){j_n = 0; d = 1 - d;} // left
            i = i_n ; j = j_n;
        }       
        return ans;
    }
};
