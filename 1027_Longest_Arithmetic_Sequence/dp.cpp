class Solution {
public:
    /*
     * Complexity: O(n^2)
     * Space: O(n^2)
     */
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>>dp; //dp[diff][index] -> the max length we can have given the diff and A[:index + 1]
        int ans = 2, size = A.size();
        if(!size) return 0;
        
        for(int j = 0; j < size; ++j){
            for(int i = 0; i < j; ++i){
                int diff = A[j] - A[i];
                // extend the previous sequence, if not exist, the base value
                // would be 2 (any two numbers)
                dp[diff][j] = dp[diff].count(i) ? dp[diff][i] + 1 : 2;
                ans = max(ans, dp[diff][j]);
            }
        }
        return ans;   
    }
};
