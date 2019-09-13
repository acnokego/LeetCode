class Solution {
public:
    /*
     * Complexity: O(kn^2)
     * Space: O(n^2)
     * /
    double largestSumOfAverages(vector<int>& A, int K) {
        int size = A.size();
        vector<double>sum(size + 1);
        vector<vector<double>>dp(size + 1, vector<double>(K + 1));
        
        
        for(int i = 1; i <= size; ++i){
            sum[i] = sum[i-1] + A[i-1];
        }
        
        if(K <= 1){
        	return sum[size] / size;
        }
        if(K >= size){
        	return sum[size];
        }
        
        // set the base case for only one group
        for(int i = 1; i <= size; ++i){
        	dp[i][1] = sum[i] / i;
        }
        for(int k = 2; k <= K; ++k){
            for(int j = k ; j <= size; ++j){
                for(int i = k-1; i <= (j - 1); ++i){
                    dp[j][k] = max(dp[i][k-1] + (sum[j] - sum[i]) / (j-i), dp[j][k]);
                }
            }
        }
        return dp[size][K];
        
    }
};
