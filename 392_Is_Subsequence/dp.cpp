class Solution {
  /*
   * Complexity: O(len(t))
   * Space: O(s)
   */
public:
    bool isSubsequence(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        vector<bool>dp(l1+1, false);
        dp[0] = true;
        
        int s_idx = 0;
        for(int i = 0; i < l2 && s_idx < l1; ++i){
            if(s[s_idx] == t[i] && dp[s_idx]){
                dp[s_idx + 1] = true;
                ++s_idx;
            }
        }
        
        return dp.back();
    }
};
