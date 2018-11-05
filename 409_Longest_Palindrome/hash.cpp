class Solution {
  /*
   * Complexity: O(l) the length of string
   * Space: O(l)
   */
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for(auto& c : s){
            counts[c] += 1;
        }
        int ans = 0;
        int max_odd_l = 0;
        for(auto it = counts.begin(); it != counts.end(); ++it){
            if((it -> second % 2) == 0) ans += (it -> second);
            else{
                if(it -> second > max_odd_l){
                    if(max_odd_l > 0) ans -= 1; // make the previous odd become even
                    ans += it -> second;
                    max_odd_l = it -> second;
                }
                // not the max odd, make it even
                else ans += (it -> second - 1);
            }
        }
        return ans;
    }
};
