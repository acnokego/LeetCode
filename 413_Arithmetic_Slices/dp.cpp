class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(n)
   */
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        
        vector<int>dp(n); // diff of A[i] - A[i-1]
        int count = 0;
        
        for(int i = 1; i < n; ++i){
            dp[i] = A[i] - A[i-1];
            int prev = i - 1;
            int length = 2;
            
            while(prev > 0 && dp[prev] == dp[i]){
                length += 1;
                
                if(length >= 3){
                    count += 1;
                }
                
                prev -= 1;
                
            }
                        
        }
        
        return count;
        
        
    }
};
