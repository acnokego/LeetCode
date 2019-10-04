class Solution {
public: 
    /*
     * Complexity: O(n * T)
     * Space: O(T)
     */
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int>dp(T+1, INT_MAX); // min number of segments to cover [0, i].
        sort(clips.begin(), clips.end(), [](const auto clip1, const auto clip2){
            return clip1[0] < clip2[0];
        });
        if(clips[0][0] != 0){
            return -1;
        }
        
        for(int i = 0; i < clips.size(); ++i){
            for(int j = clips[i][0]; j <= min(clips[i][1], T); ++j){
                // init, starting from 0
                if(clips[i][0] == 0){
                    dp[j] = 1;
                } else {
                // find dp[start] of this interval and update all the value in this interval 
                    dp[j] = (dp[clips[i][0]] == INT_MAX) ? INT_MAX : min(dp[clips[i][0]] + 1, dp[j]);
                }
            } 
        }
        return dp[T] == INT_MAX ? -1 : dp[T];
    }
};
