class Solution {
  /*
   * Complexity: O(max(len(s), len(p)))
   * Space: O(1) #26
   */
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        // count occurrence of each vocabulary in p
        vector<int>p_count(26, 0);
        for(auto c : p){
            ++p_count[c - 'a'];
        }
        vector<int>sub_count(26, 0);
        // count occurrence of each vocabulary in the substring starting from
        // the first index.
        if(s.length() < p.length()) return ans;
        for(int i = 0; i < p.length(); ++i){
            ++sub_count[s[i] - 'a'];
        }
        if(p_count == sub_count) ans.push_back(0);
        --sub_count[s[0] - 'a'];
        // sliding window by one character a time
        for(int i = 1; i < s.length() - p.length() + 1; ++i){
            ++sub_count[s[i + p.length() - 1] - 'a'];
            if(p_count == sub_count) ans.push_back(i);
            --sub_count[s[i] - 'a'];
        }
        return ans;
    }
};
