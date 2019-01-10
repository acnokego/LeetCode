class Solution {
  /*
   * Complexity: O(l^2)
   * Space: O(l^2)
   */
public:
    int longestPalindromeSubseq(string s) {
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        
        // find the LCS between reverse_s and s.
        int l = s.length();
        vector<vector<int>>dp(l + 1, vector<int>(l + 1));
    
        for(int i = 0; i <= l; ++i){
            for(int j = 0; j <= l; ++j){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i-1] == reverse_s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[l][l];
    }
};
