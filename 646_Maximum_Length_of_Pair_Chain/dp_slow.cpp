class Solution {
public:
    /*
     * Complexity: O(n^2)
     * Space: O(n)
     */
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),[](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
            
        });
        
        int size = pairs.size();
        if(!size) return 0;
        int max_len = 1;
        vector<int>dp(size, 1);
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < i; ++j){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
