class Solution {
public:
    /*
     * Complexity: O(nm)
     * Space: O(mn)
     */
    bool isMatch(string s, string p) {
        if(!s.length() && !p.length()){
            return true;
        }
        
        int len_s = s.length();
        int len_p = p.length();
        
        vector<vector<bool>>dp(len_s + 1, vector<bool>(len_p + 1, false));
        dp[0][0] = true;
        
        for(int j = 1; j <= len_p; ++j){
            if(p[j - 1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
        }
        
        for(int i = 1; i <= len_s; ++i){
            for(int j = 1; j <= len_p; ++j){
                if((s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1]){
                    dp[i][j] = true;
                } else if (p[j-1] == '*' && ( dp[i-1][j] || dp[i][j-1])){
                    // star is empty sequence or star like any sequence.
                    dp[i][j] = true;
                }
            }
        }
        return dp[len_s][len_p];
    }
};
