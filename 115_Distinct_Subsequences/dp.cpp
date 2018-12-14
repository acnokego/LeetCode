class Solution {
  /*
   * Complexity: O(l2 * l1*l1)
   * Space: O(l1)
   */
public:
    int numDistinct(string s, string t) {
        
        int l1 = s.length();
        int l2 = t.length();
        
        // number of subsequence match when end at ith index
        vector<int>dp(l1, 0);
        
        // considering t[0...i]
        for(int i = 0; i < l2; ++i){
            
            // have to be at least i+1 characters to have the subsequencesa
            // starting from the end, since we are using value of last iteration
            for(int j = l1 - 1; j >= i; --j){
                
                // initialization base case i = 0
                if(i == 0 && s[j] == t[i]){
                    dp[j] = 1;
                }
                
                else{
                    // reintialize for this iteration t[0...i].
                    dp[j] = 0;
                    
                    // if we match t[i]
                    if(s[j] == t[i]){
                        // add all counts of dp[k] that has subsequence match t[0...i-1] 
                        // k would be smaller than j and bigger than i-1
                        for(int k = j - 1; k >= (i - 1); --k){
                            dp[j] += dp[k];
                        }
                    }
                }
                
            }
        }
        
        // sum all the counts
        // starting from the length of t
        int ans = 0;
        for(int i = l2 - 1; i < l1; ++i){
            ans += dp[i];
        }
        return ans;
    }
};
