class Solution {
public:
    /*
     * Complexity: O(a*b)
     * Space: O(a*b)
     */
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int size_a = A.size();
        int size_b = B.size();
        if(!size_a || !size_b) {
            return 0;
        }
        vector<vector<int>>dp(size_a + 1, vector<int>(size_b + 1, 0));
        
        for(int i = 0; i <= size_a; ++i){
            for(int j = 0; j <= size_b; ++j){
                if(i == 0 || j == 0) continue;
                if (A[i-1] == B[j-1])dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[size_a][size_b];
    }
};
