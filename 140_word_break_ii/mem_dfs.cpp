class Solution {
  /*
   * Complexity: O(n^2) each word in dict of length 1
   * Space: O(n)
   */
public:
    vector<string> combine(vector<string>prev_ans, string word){
        vector<string>ret;
        for(int i = 0; i< prev_ans.size(); ++i){
            ret.push_back(prev_ans[i] + " " + word);
        }
        return ret;
    }
    vector<string> wordBreak_helper(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& cache){
        vector<string>ans;
        if(cache.count(s)) return cache[s];
        if(dict.count(s)) {
            ans.push_back(s);
        }
        for(int i = 1; i < s.length(); ++i){
            string word = s.substr(i); // s[i...l-1];
            // if it is in dict, separate it with space and try to find all possible combinations
            // of s[0...i-1]
            if(dict.count(word)){
                string prev_s = s.substr(0, i);
                vector<string>tmp_ans = combine(wordBreak_helper(prev_s, dict, cache), word);
                ans.insert(ans.end(), tmp_ans.begin(), tmp_ans.end());
            }
        }
        cache[s] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict){
        unordered_set<string> dict;
        for(auto& w: wordDict){
            dict.insert(w);
        }
        unordered_map<string, vector<string>>cache;
        return wordBreak_helper(s, dict, cache);
    }
};
