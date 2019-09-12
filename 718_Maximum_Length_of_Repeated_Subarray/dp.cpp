class Solution {
public:
    /*
     * Complexity: O(mn)
     * Space: O(mn)
     */
    int findLength(vector<int>& A, vector<int>& B) {
        
        int l_a = A.size(), l_b = B.size();
        if(!l_a || !l_b) return 0;
        // dp[i][j] the maximum array end at A[i] and B[j]
        vector<vector<int>>dp(l_a + 1, vector<int>(l_b + 1));
        int max_len = 0;
        for(int i = 0; i <= l_a; ++i){
            for(int j = 0; j <= l_b; ++j){
                if(i == 0 || j == 0) continue;
                if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};
