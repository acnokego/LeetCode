class Solution {
  /*
   * Complexity: O(len(s1)*len(s2))
   * Space: O(len(s1)*len(s2))
   * O(n) Space:
   * https://leetcode.com/problems/edit-distance/discuss/25911/My-O(mn)-time-and-O(n)-space-solution-using-DP-with-explanation
   */
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        // let dp[i][j] be the min distance between s1[0..i-1] and s2[0..j-1]
        // initialization
        for(int i = 0; i <= word1.length(); ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j <= word2.length(); ++j){
            dp[0][j] = j;
        }
        // for each dp[i][j], there are two possible cases:
        // 1. (s1[i-1] == s2[j-1]) dp[i][j] == dp[i-1][j-1], no need to modify the last character.
        // 2. need to modify the last character of s1, we can
        //  a. delete the last character of s1 (s1[i-1])
        //  b. insert the last character of s2 (s2[j-1])
        //  c. replace the last character of s1 (s1[i-1]) with s2[j-1]
        for(int i = 1; i <= word1.length(); ++i){
            for(int j = 1; j <= word2.length(); ++j){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};
