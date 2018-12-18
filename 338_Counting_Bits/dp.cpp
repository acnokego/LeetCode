class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   */
public:
    vector<int> countBits(int num) {
        vector<int>dp(num + 1, 0);
        
        for(int i = 1; i <= num; ++i){
            
            // the last bit is 1, mod 2 != 0
            if(i & 1){
                dp[i] = dp[i/2] + 1;
            }
            else{
                dp[i] = dp[i/2];
            }
            
        }
        
        return dp;
    }
};
