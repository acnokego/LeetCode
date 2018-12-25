class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
public:
    int numTrees(int n) {
        
        if(!n) return 0;
        
        vector<int>dp(n + 1); // dp[i] : the number of unique BST we can have for values 1... i
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){ // let j be the root
                // the number of the left subtree * the number of right subtree
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
        
    }
};
