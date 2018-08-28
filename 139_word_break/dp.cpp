class Solution {
  /*
   * Complexity: O(n^2) assume substr is O(1) but its actually O(n)
   * Space: O(max(n, w))
   * Optimize: use a vector to store previous matching index
   */
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for(auto & w : wordDict){
            hash.insert(w);
        }
        int l = s.length();
        if(!l) return false; 
        vector<bool>dp(l+1);
        dp[0] = true;
        // let dp[i] be if s[0..i-1] breakable
        for(int i = 1; i <= l; ++i){
            // for index 0 -> i-1
            // we know s[0..j-1] is true
            // then substr j -> i - 1
            for(int j = 0; j < i; ++j ){
                if(dp[j] && hash.find(s.substr(j, i-j)) != hash.end()){
                    dp[i]= 1;
                    break;
                }
            }
        }
        return dp[l];
    }
};
