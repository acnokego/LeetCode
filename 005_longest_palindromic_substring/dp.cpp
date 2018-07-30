class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n^2)
   */
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans;
        if(n == 0) return ans;
        vector<vector<bool>>dp(n, vector<bool>(n));

        int start_idx = 0, end_idx = 0;
        int ans_length = INT_MIN;
        for(int j = 0; j < n; ++j){
            for(int i = j; i >= 0; --i){
                if(i == j) dp[i][j] = 1;
                else if(i + 1 == j && s[i] == s[j]) dp[i][j] = 1;
                else if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
                
                if(dp[i][j] && (j - i + 1 > ans_length)){
                    start_idx = i;
                    end_idx = j;
                    ans_length = j - i + 1;
                }
            }
            
        }
        ans = s.substr(start_idx, end_idx - start_idx + 1);
        return ans;
    }
};
