class Solution {
  /*
   * Complexity: O(s*m*n)
   * Space: O(m*n)
   */
public:
    pair<int, int>count_s(string & s){
        pair<int, int>ans = make_pair(0,0);
        for(char& c : s){
            if(c == '0'){
                ans.first += 1;
            }
            else if(c == '1'){
                ans.second += 1;
            }
        }
        return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        int dp[m+1][n+1];
        // down to int* type
        fill(dp[0], dp[m+1], 0);

        for(string& s : strs){
            pair<int, int>count = count_s(s);
            // need to start from the m, n
            // since we are going to use table at the last iteration
            // if we start from 0, dp[j- count.first][k-count.second] may
            // has been modified in this iteration
            for(int j = m; j >= count.first; --j){
                for(int k = n; k >= count.second; --k){
                    dp[j][k] = max(dp[j][k], dp[j-count.first][k - count.second] + 1);
                }
            }
            
        }
        
        return dp[m][n]; 
    }
};
