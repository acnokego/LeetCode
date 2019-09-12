class Solution {
public:
    /*
     * Complexity: O(n^2)
     * Space: O(n^2)
     */
    int lenLongestFibSubseq(vector<int>& A) {
        
        int ans = 0;
        int s = A.size();
        unordered_map<int, int>idx;
        vector<vector<int>>dp(s, vector<int>(s));
        //dp[i][j] indicate the fibonacci sequence with the last two elements 
        //to be A[i], A[j]
        
        for(int j = 0; j < s; ++j){
            idx[A[j]] = j;
            for (int i = 0; i < j; ++i){
                // if the previous element exist, and not equal to A[i]
                if(idx.count(A[j] - A[i]) && (A[j] - A[i]) < A[i]){
                    int x_idx = idx[A[j]-A[i]];
                    dp[i][j] = dp[x_idx][i] + 1;
                } else{
                    dp[i][j] = 2;
                }
                ans = max(dp[i][j], ans);
            }
        }
        return ans > 2 ? ans : 0;
    }
};
