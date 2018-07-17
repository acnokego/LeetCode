class Solution {
  /*
   * Complexity: O(n),( O(26n) separate by all letters)
   * Space: O(n) stacks
   */
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        vector<int>occ(256, 0);
        int l = s.length();
        for(int i = 0; i < l; ++i){
            ++occ[int(s[i])];
        }
        int separate = 0;
        // if we find a letter that its occurrence is less than k, than it must
        // not be included in the answer. so we use it to separate the string.
        while(separate < l && occ[int(s[separate])] >= k) ++separate;
        if(separate == l) return l;
        int left = longestSubstring(s.substr(0, separate), k);
        int right = longestSubstring(s.substr(separate + 1), k);
        return max(left, right);      
    }
};
