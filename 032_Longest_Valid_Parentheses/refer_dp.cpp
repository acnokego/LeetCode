class Solution {
  /*
   * Complexity: O(l)
   * Space: O(l)
   */
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int l = s.length();
        vector<int>dp(l); // the length of valid parentheses end at i
        for(int i = 1; i < l; ++i){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = (i-2) >= 0 ? dp[i-2] + 2 : 2; 
                    ans = max(ans, dp[i]);
                }
                // if s[i-1] == ')'
                else{
                    // to find the '(' that is closen by i-1
                    if((i - dp[i-1] - 1) >= 0 && s[i-dp[i-1]-1] == '('){
                        dp[i] = dp[i-1] + 2 + (((i-dp[i-1]-2) >= 0) ? dp[i-dp[i-1]-2] : 0);
                        ans = max(ans, dp[i]);
                    }
                    
                }
            }
            
        }
        return ans;
        
    }
};
