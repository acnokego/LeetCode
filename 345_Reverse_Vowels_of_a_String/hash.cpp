class Solution {
  /*
   * Complexit: O(n)
   * Space: O(n)
   */
public:
    string reverseVowels(string s) {
        int l = s.length();
        string ans = s;
        if(l){
            vector<char>vowel_order;
            vector<int>idx_order;
            unordered_set<char> vowels = {{'a'}, {'e'}, {'i'}, {'o'}, {'u'}, {'A'}, {'E'}, {'I'}, {'O'}, {'U'}};
            for(int i = 0; i < l; ++i) {
                if(vowels.find(s[i]) != vowels.end()) {
                    vowel_order.push_back(s[i]);
                    idx_order.push_back(i);
                }
            }
            for(int i = 0; i < idx_order.size(); ++i){
                ans[idx_order[i]] = vowel_order[vowel_order.size() - 1 - i];
            }
        }
        return ans;
    }
};
