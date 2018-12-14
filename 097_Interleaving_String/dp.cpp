class Solution {
  /*
   * Complexity: O(l3^2)
   * Space: O(l1*l2)
   */
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        // when we only considering s1[0...i-1], s2[0...j-1], can we have the s3 output?
        vector<vector<bool>>dp(l1 + 1, vector<bool>(l2 + 1, false));
        
        if(l3 == 0) dp[0][0] = true;
        for(int k = 1; k <= l3; ++k){
            if(k == 1){
                if( l1 > 0 && s1[0] == s3[0]) dp[1][0] = true;
                if( l2 > 0 && s2[0] == s3[0]) dp[0][1] = true;
                continue;
            }
            // get previous value when considering (k-1)
            for(int i = 0; i <= min(l1, k-1); ++i){
                // the total numbers of considering character must == k-1 
                int j = k - 1 - i;
                if(j > l2) continue;
                
                // considering s1[0...i-1], s2[0...j-1], we can have s3[0...k-2]
                if(dp[i][j]){
                    // add the next char in s1 (i-1+1)
                    // if the s1[i] == s3[k-1]
                    if( i < l1 && s1[i] == s3[k-1]) dp[i+1][j] = true;
                    // add the next char in s2 (j-1+1)
                    if( j < l2 && s2[j] == s3[k-1]) dp[i][j+1] = true;
                }
            }
        }

        return ((l1 + l2) < l3) ? false : dp[l1][l2];
        
    }
};
