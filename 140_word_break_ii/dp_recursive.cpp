class Solution {
public:
    void recursive(vector<string>&ans, string& tmp_ans, vector<vector<int>>& parent_idx, int start){
        for(int i = 0; i < parent_idx[start].size(); ++i){
            if(parent_idx[start][i] < 0){
                ans.push_back(tmp_ans);
                continue;
            }
            tmp_ans.insert(parent_idx[start][i] + 1, " ");
            recursive(ans, tmp_ans, parent_idx, parent_idx[start][i]);
            tmp_ans.erase(parent_idx[start][i]+1, 1);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>hash;
        for(auto& w : wordDict){
            hash.insert(w);
        }
        vector<string>ans;
        int l = s.length();
        if(!l) return ans;
        vector<bool>dp(l+1);
        dp[0] = true;
        // for each match_idx there would be 
        vector<vector<int>>parent_idx(l);
        for(int i = 1; i <= l; ++i){
            for(int j = i-1 ; j >= 0; --j){
                if(dp[j] && hash.find(s.substr(j, i-j)) != hash.end()){
                    dp[i] = 1;
                    parent_idx[i-1].push_back(j-1);
                }
            }
        }
        if(!dp[l]) return ans;
        recursive(ans, s, parent_idx, l-1);
        return ans;
    }
};
