class Solution {
public:
    /*
     * Complexity: O(n*2^n), n is the length of the square -> O(N) total number
     * of nodes
     * Space: O(n) -> O(n^2)
     *
     * Using cache here to reduce complexity (dynamic programming).
     * cache[row][col] indicate the smallest sum starting from row, col.
     *
     * There would be simpler way:
     *  we can only store the sum of path from the last row.
     */
    // return the sum of the smallest falling path
    int dfs(int& ans, int prev_sum, const vector<vector<int>>& A, int row, int col,
            vector<vector<int>>& cache){
        
        int next_sum; 
        if(A.size() - 1 == row) {
            prev_sum += A[row][col];
            ans = (prev_sum < ans) ? prev_sum : ans;
            cache[row][col] = A[row][col];
            return A[row][col]; 
        } else {
            int ret_sum1 = INT_MAX, ret_sum2 = INT_MAX, ret_sum3 = INT_MAX;
            if((col + 1) <= (A[0].size() - 1)){
                if(cache[row+1][col+1] != INT_MAX){
                    ret_sum1 = cache[row+1][col+1];   
                } else {
                    ret_sum1 = dfs(ans, prev_sum + A[row][col], A, row + 1, col + 1, cache);
                }
            }
            if ((col - 1) >= 0) {
                if(cache[row+1][col-1] != INT_MAX){
                    ret_sum2 = cache[row+1][col-1];   
                } else {
                 ret_sum2 = dfs(ans, prev_sum + A[row][col], A, row + 1, col - 1, cache);
                }
            }
            if (cache[row+1][col] != INT_MAX) {
                ret_sum3 = cache[row+1][col]; 
            }
            else {
                ret_sum3 = dfs(ans, prev_sum + A[row][col], A, row+1, col, cache);
            }
            next_sum = min({ret_sum1, ret_sum2, ret_sum3});
        }
        int sum = next_sum + prev_sum + A[row][col];
        ans = (sum < ans) ? sum : ans;
        cache[row][col] = next_sum + A[row][col];
        return cache[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int ans = INT_MAX;
        int row_num = A.size();
        if(!row_num) return 0;
        int col_num = A[0].size();
        if(!col_num) return 0;
        
        vector<vector<int>>cache(row_num, vector<int>(col_num, INT_MAX));
        for(int i = 0; i < col_num; ++i){
            int temp_sum = 0;
            dfs(ans, temp_sum, A, 0, i, cache);
        }
        return ans;
    }
};
